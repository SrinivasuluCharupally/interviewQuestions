#include<iostream>
#include<vector>

using namespace std;

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}


void recursion(int *input, int start, int end, vector<int> tmpArray, vector<vector<int>> &resultMatrix, int targetSum, int sum, int second) {
	if(start >= end) return;

	
	if(tmpArray.size() < 4 ) {
		sum += input[start];
		tmpArray.push_back(input[start]);
		recursion(input, start+1, end, tmpArray, resultMatrix, targetSum, sum, second);

		if(tmpArray.size() == 4) {
			if(sum == targetSum) resultMatrix.push_back(tmpArray);
		}
	}

	else {

	
	for(int i = 0; i < 4; i++){
//		int j = i;
//		while(j>=0) {
			sum -= tmpArray[tmpArray.size() -1];
			tmpArray.pop_back();
//			j--;
//		}
		recursion(input, start, end, tmpArray, resultMatrix, targetSum, sum, second);
	}



	sum = 0;
	recursion(input, second+1, end, tmpArray, resultMatrix, targetSum, sum, second);

	}
}


void withoutrecursion( int *input, int arraySize) {
	int sum=0, targetSum=0;
//	vector<int> tmpArray;
//	int arraySize = sizeof(input) / sizeof(int) ;

	vector<vector<int>> resultMatrix;
	int end = arraySize - 4;
	int j = 0;
	int start = 0;
  while(j <= end) {
	vector<int> tmpArray;
	start = j;
	for(int i =j; tmpArray.size() < 4 && start < arraySize ; ++i, start++) {
		sum += input[start];
		tmpArray.push_back(input[start]);

		if(tmpArray.size() == 4) {
			if(sum == targetSum) resultMatrix.push_back(tmpArray);
		}
	}

	for(int i =0; i < 4; ++i) {

		sum -= tmpArray[tmpArray.size() -1];
		tmpArray.pop_back();
		
		vector<int> localtmp = tmpArray;
		int localsum = sum;
		int localstart = start;

		for(int i = 0; i < (arraySize - 4 + j) && localstart <= arraySize; i++) {
			while(localtmp.size() <4 && localstart < arraySize) {
				localsum += input[localstart];
				localtmp.push_back(input[localstart]);
				localstart++;
			}
		
			if(localtmp.size() == 4) {
				if(localsum == targetSum) resultMatrix.push_back(localtmp);
			}
			localtmp = tmpArray;
			localsum = sum;
			
		}

	}

  j++;
  }
  

	for(int i =0; i <resultMatrix.size(); i++) {
		for(int j =0; j < resultMatrix[i].size(); j++)
			cout << resultMatrix[i][j] << " " ;
		cout << endl;
	}

}
int main() {
	int input[] = {1, 0, -1, 0, -2, 2};
	int arraySize = sizeof(input) / sizeof(int);

	qsort(input, arraySize, sizeof(int), compare);
	for(int i =0; i < arraySize; i++)
		printf("%d ", input[i]);

	cout << endl;


	int start=0, targetSum=0, sum=0;
	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

//	recursion(input, start, arraySize, tmpArray, resultMatrix, targetSum, sum, 0);
	withoutrecursion(input, arraySize);

	for(int i =0; i <resultMatrix.size(); i++) {
		for(int j =0; j < resultMatrix[i].size(); j++)
			cout << resultMatrix[i][j] << " " ;
		cout << endl;
	}
}
