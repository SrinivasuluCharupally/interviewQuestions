#include<iostream>
#include<vector>

using namespace std;

int recursion(bool *input, int start, int end, int next, vector<bool> &tmpArray, vector<vector<bool>> &resultMatrix) {
	if(start >= end) return 0 ;
	if( next >= end) return 1;

	else {

		if(start < next) cout << input[start] << " " ;
		else {
		if(input[start] == 0) { cout << 1 << " " ; input[start] = true; }
		else { cout << 0 << " "; input[start] = false; }
		}

		if(recursion(input, start+1, end, next, tmpArray, resultMatrix) == 1) return 1;

		cout << endl;

		return recursion(input, 0,  end, next+1, tmpArray, resultMatrix);
	}
}


int main() {
	bool input[] ={0,1,0,1};
	int arraySize = sizeof(input) / sizeof(bool);

	vector<bool> tmpArray;
	vector<vector<bool>> resultMatrix;

	recursion(input, 0, arraySize, 0, tmpArray, resultMatrix);
//	for(int i = 0; i < resultMatrix.size(); i++) {
//		for(int j = 0; j < resultMatrix[i].size(); j++)
//			cout << resultMatrix[i][j] << " " ;
//		cout << endl;
//	}
}
