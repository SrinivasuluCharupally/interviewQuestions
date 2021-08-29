#include<iostream>
#include<vector>

using namespace std;

void recursion(int *input, int start, int end, vector<int> &tmpArray, vector<vector<int>> &resultMatrix, int targetSum, int sum) {
	if(start >= end) return;


	sum += input[start];
	tmpArray.push_back(input[start]);

	if(sum == targetSum) resultMatrix.push_back(tmpArray);
	if(tmpArray.size() == 2) { 
		sum -= tmpArray[tmpArray.size() - 1];
		tmpArray.pop_back();
	}


	recursion(input, start+1, end, tmpArray, resultMatrix, targetSum, sum); 
	sum = 0;
	recursion(input, start+1, end, tmpArray, resultMatrix, targetSum, sum);

	
}

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
void recusrion_single(int *input, int start, int end, vector<int> &tmpArray, vector<vector<int>> &resultMatrix, int targetSum, int sum){
	if(start == end) return;

	sum = input[start] + input[end-1];
	if(sum == targetSum)  {
		resultMatrix.push_back({input[start], input[end-1]});
		sum = 0;
		recursion(input, start+1, end-1, tmpArray, resultMatrix, targetSum, sum); 
	}
	if(sum > targetSum) {
		sum -= input[end-1];
		recursion(input, start, end-1, tmpArray, resultMatrix, targetSum, sum); 
	}
	if(sum < targetSum) {
		sum -= input[start];
		recursion(input, start+1, end, tmpArray, resultMatrix, targetSum, sum); 
	}

}



int main() {
	int input[] = {2, 7, 11, 15};
	int arraySize = sizeof(input) / sizeof(int) ;

	int start = 0, targetSum = 9, sum=0;
	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

	recursion(input, start, arraySize, tmpArray, resultMatrix, targetSum, sum);
	for(int i =0; i < resultMatrix.size(); i++) {
		for(int j = 0; j < resultMatrix[i].size(); ++j)
			cout << resultMatrix[i][j] << " " ;
		cout << endl;
	}

	qsort(input, arraySize, sizeof(int), compare);
	int sum1 =0;
	vector<int> tmpArray1;
	vector<vector<int>> resultMatrix1;
	recusrion_single(input, start, arraySize, tmpArray, resultMatrix1, targetSum, sum1);


	for(int i =0; i < resultMatrix1.size(); i++) {
		for(int j = 0; j < resultMatrix1[i].size(); ++j)
			cout << resultMatrix1[i][j] << " " ;
		cout << endl;
	}

}
