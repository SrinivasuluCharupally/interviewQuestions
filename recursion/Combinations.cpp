#include <iostream>
#include <vector>

using namespace std;

void recursion(vector<int> &input, int n, int start, int k, vector<int> &tempArray, vector<vector<int>> &resultMatrix) {
	if(start>n) return;
	if(tempArray.size() == k) { 
		resultMatrix.push_back(tempArray);
		return;
	}

	tempArray.push_back(input[start]);
	recursion(input, n, start+1, k, tempArray, resultMatrix);
	tempArray.pop_back();
	recursion(input, n, start+1, k, tempArray, resultMatrix);
}



int main() {
	int n = 4, k = 2;

	vector<int> input;
	for(int i =1; i <= n; i++) { 
		input.push_back(i);
		printf(" %d " , input[i]);
	}

	vector<vector<int>> resultMatrix;
	vector<int> tempArray;
	recursion(input, n, 0, k, tempArray, resultMatrix);

	for(int i = 0; i < resultMatrix.size(); i++) {
		printf(" \n");
		for(int j = 0; j < resultMatrix[i].size(); j++)
			printf(" %d ", resultMatrix[i][j]);
	}

}
