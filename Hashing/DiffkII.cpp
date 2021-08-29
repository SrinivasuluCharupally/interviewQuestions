#include<iostream>
#include<vector>

using namespace std;


void recursion(int *input, int start, int end, vector<int> &tmpArray, vector<vector<int>> &resultMatrix, int firstValue, int target) {
	if(start >= end) return;
	
	if(abs(firstValue - input[start])  == target) {
		resultMatrix.push_back({firstValue, input[start]});
		return;
	}



	recursion(input, start+1, end, tmpArray, resultMatrix, firstValue, target);
	
	firstValue = input[start];
	recursion(input, start+1, end, tmpArray, resultMatrix, firstValue, target);


}


int main() {
	int input[] = {1,5,3};
	int arraySize = sizeof(input) / sizeof(int) ;

	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

	int diff = 0;
	int target = 2;
	int firstValue = input[0];
	recursion(input, 1, arraySize, tmpArray, resultMatrix, firstValue, target);

	for(int i = 0; i < resultMatrix.size(); i++){
		for(int j = 0; j < resultMatrix[i].size(); j++)
			cout << resultMatrix[i][j] << " " ;

		cout << endl;
	}
}
