#include<iostream>
#include<vector>

using namespace std;


void recursion(int *input, int start, int end, vector<int> &tempArray, vector<vector<int>> &resultMatrix) {
	if(tempArray.size() == 1) return;

	else {
		vector<int> tmp;
		for(int i = start; i < end; i++) {
			
//			tempArray.push_back(input[i]);
			
			tmp.push_back(input[i]);
			resultMatrix.push_back(tmp);

			recursion(input, start+i, end, tmp, resultMatrix);
		}
	}
	

}


void recursionWithouForLoop(int *input, int start, int end, vector<int> &tempArray, vector<vector<int>> &resultMatrix) {
//	if(start >= end) return;

	if(start >= end ) {
		resultMatrix.push_back(tempArray);
		return;
	}

	else {
		recursionWithouForLoop(input, start+1, end, tempArray, resultMatrix);
		tempArray.push_back(input[start]);
		recursionWithouForLoop(input, start+1, end, tempArray, resultMatrix);
		tempArray.pop_back();
	}
}



int main() {
	int input[3] = {1,2,3};
	int start = 0, end = sizeof(input) / sizeof(int);

	vector<int> tempArray;
	vector<vector<int>> resultMatrix;

	recursion(input, start, end, tempArray, resultMatrix);

	for(int i = 0; i < resultMatrix.size(); i++) {
		printf(" \n ");
		for(int j = 0; j < resultMatrix[i].size(); j++)
			cout << resultMatrix[i][j];
		printf(" \n ");
	}

	vector<int> tempArray2;
	vector<vector<int>> resultMatrix2;
	recursionWithouForLoop(input, start, end, tempArray2, resultMatrix2);


	for(int i = 0; i < resultMatrix2.size(); i++) {
		printf(" \n ");
		for(int j = 0; j < resultMatrix2[i].size(); j++)
			cout << resultMatrix2[i][j];
		printf(" \n ");
	}

}
