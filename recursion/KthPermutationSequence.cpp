#include<iostream>
#include<vector>

using namespace std;

void recursion(int start, int end, vector<int> &input, vector<int> &tempArray, vector<vector<int>> &resultMatrix) {
	if(start == end) {
		resultMatrix.push_back(tempArray);
		return;
	}
	else {
		for(int i = start; i < end; i++) {
			swap(tempArray[start], tempArray[i]);
			recursion(start+1, end, input, tempArray, resultMatrix);
			swap(tempArray[start], tempArray[i]);
		}
	}

}


int main() {
	int n = 3;
	vector<int> input;
	for(int i =0; i < n; i++) 
		input.push_back(i);

	vector<int> tempArray = input;
	vector<vector<int>> resultMatrix;

	recursion(0, n, input, tempArray, resultMatrix);

	for(int i =0; i < resultMatrix.size(); i++) {
		printf(" \n");
		for(int j =0; j < resultMatrix[i].size(); j++)
			printf(" %d ", resultMatrix[i][j]);
	}
}
