#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> A, vector<int> B, int &aleft, int &aright, int &bleft, int &bright, vector<int> &result) {
	if(aleft > aright || bleft > bright) return;

	if(A[aleft] < B[bleft] && A[aright] > B[bright])  { 
		aleft +=1; aright -=1; recursion(A, B, aleft, aright, bleft, bright, result); }
	else if(A[aleft] < B[bleft] && A[aright] == B[bright] ) { 
		result.push_back(A[aright]); aleft +=1; aright -=1; bright -=1; recursion(A, B, aleft, aright, bleft, bright, result);}
	else if(A[aleft] == B[bleft] && A[aright] > B[bright] ) { 
		result.push_back(A[aleft]); aleft +=1; aright -=1; bleft +=1; recursion(A, B, aleft, aright, bleft, bright, result); }
	else if(A[aleft] == B[bleft] && A[aright] == B[bright] ){ 
		if(aleft != aright) {result.push_back(A[aright]); result.push_back(A[aleft]); }
		else result.push_back(A[aright]);
		aleft +=1; aright -=1; bleft +=1; bright -=1; recursion(A, B, aleft, aright, bleft, bright, result); }

}

int main() {
	vector<int> A = {1, 2, 3, 3, 4, 5, 6};
	vector<int> B =       {3, 3,    5};
	vector<int> result;
	int aleft=0, aright=A.size()-1, bleft = 0, bright = B.size()-1;

	recursion(A, B, aleft, aright, bleft, bright, result);

	for(int i = 0; i < result.size();  i++) cout << result[i] << " " ;

}
