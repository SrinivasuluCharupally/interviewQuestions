#include<iostream>
#include<vector>
#include<climits>

#include<algorithm>

// important / impartent
//
using namespace std;

int compare(void *a, void *b) {
	return *(int*)a - *(int*)b;

}

// 2 3 4
// 1 2 5
// 1 3 4
void recursion(vector<int> A, vector<int> B, vector<int> C,  int &i, int &j, int &k, int &result) {
	if(i >= A.size() || j >= B.size() || k >= C.size()  ) return;

	int t1 = A[i] - B[j];
	int t2 = B[j] - C[k];
	int t3 = C[k] - A[i];

	result = min(result, max(abs(t1), max(abs(t2), abs(t3))));

	if(abs(t1)>=abs(t2) && abs(t1)>=abs(t3))
        {
            if(t1>0) { j +=1;
	     recursion(A, B, C, i, j, k, result); }
            else { i +=1;
	     recursion(A, B, C, i, j, k, result); }
        }
        else if(abs(t2)>=abs(t1) && abs(t2)>=abs(t3))
        {
            if(t2>0) { k += 1;
	     recursion(A, B, C, i, j, k, result); }
            else { j += 1;
	     recursion(A, B, C, i, j, k, result); }
                
        }
        else if(abs(t3)>=abs(t1) && abs(t3)>=abs(t2))
        {
            if(t3>0) { i +=1;
	     recursion(A, B, C, i, j, k, result); }
            else { k += 1; 
	     recursion(A, B, C, i, j, k, result); }
        }

 
}

int main() {
	vector<int> A = {1,4,10}; // -4 -1 1 2
	vector<int> B= {2, 15, 20};
	vector<int> C = {10,12};


 	//sort(input.begin(), input.end());

	int result = INT_MAX, diff = INT_MAX, target = 1;
	int i = 0, j = 0, k=0;
	recursion(A, B, C, i, j, k , result);
	
	cout << "Closet to given tart " << result << endl;
}


