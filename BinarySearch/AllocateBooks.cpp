#include<iostream>
#include<vector>

using namespace std;

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void recursion(int *input, int start, int end, vector<int> &tempArray, vector<vector<int>> &resultMatrix, int sum) {
	if(start >= end) return;

	else {
		//recursion(input, start+1, end, tempArray, resultMatrix)l;

		if(tempArray.size() !=0 ) tempArray.pop_back();
		
		tempArray.push_back(input[start]);
		sum += input[start];
		tempArray.push_back(sum);
		resultMatrix.push_back(tempArray);

		recursion(input, start+1, end, tempArray, resultMatrix, sum);
		
	}
	


}

int main() {
	int input[4] = {12,34,67,90};
	vector<int> tempArray;
	vector<vector<int>> resultMatrix;

	int start = 0, end = 4, totalPages=0, sum=0;

	qsort(input, 4, sizeof(int), compare);
	printf("Input Array \n");
	for(int i =0; i < 4; i++) {
		printf(" %d ", input[i]);
		totalPages += input[i];
	}


	recursion(input, start, end, tempArray, resultMatrix, sum);

	printf("\nPossible Solutions\n");
	for(int i =0; i < resultMatrix.size(); i++) {
		printf("s1 = %d , s2 = %d ", resultMatrix[i][resultMatrix[i].size()-1], totalPages-resultMatrix[i][resultMatrix[i].size()-1]);
		for(int j = 0; j < resultMatrix[i].size()-1 ; j++)
			printf(" %d ", resultMatrix[i][j]);
		printf(" \n");
	}
}
