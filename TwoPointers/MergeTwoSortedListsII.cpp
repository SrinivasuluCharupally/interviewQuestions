#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> &A, vector<int> B, int &Aposition, int &Bposition) {
	if(Bposition >= B.size() ) return;


	
	 if((A[Aposition] <= B[Bposition] && A[Aposition+1] >= B[Bposition] && Aposition < A.size()) || ((A[Aposition] <= B[Bposition] ) && Aposition == A.size()-1 )  ) {
		A.insert(A.begin()+Aposition+1, B[Bposition]);
		Aposition +=1;
		Bposition +=1;
	 }	
	 else if(Aposition <= A.size() ) {
		Aposition +=1;
	 }


	recursion(A, B, Aposition, Bposition);
}


int main() {
	vector<int> A = {1,5,8};
	vector<int> B = {6,9};
	int Aposition = 0;
	int Bposition = 0;
	recursion(A,B, Aposition, Bposition);

	for(int i = 0; i < A.size(); i++)
		cout << A[i] ;

	cout << endl;

}
