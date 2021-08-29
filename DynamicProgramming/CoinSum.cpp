#include<iostream>
#include<vector>

using namespace std;

void recursion(int *input, int start, int end, int sum, vector<int> &tmpArray, vector<vector<int>> &resultMatrix) {
	if(start > end || sum > 4) return;
	if(sum == 4) {
		resultMatrix.push_back(tmpArray);
		return;
	}
	
	else {
		tmpArray.push_back(input[start]);
		sum += input[start];
		recursion(input, start, end, sum, tmpArray, resultMatrix);

		sum -= tmpArray[tmpArray.size() -1];
		tmpArray.pop_back();
		recursion(input, start+1, end, sum, tmpArray, resultMatrix);
	}		

}

int main() {
	int input[] = {1, 2, 3};
	int arraySize = sizeof(input) / sizeof(int), sum = 0;
	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

	recursion(input, 0, arraySize, sum, tmpArray, resultMatrix);

	for(int i = 0; i < resultMatrix.size(); i++) {
		for(int j = 0; j < resultMatrix[i].size(); j++)
			cout << resultMatrix[i][j] << " ";
		cout << endl;
	}
}
