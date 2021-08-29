#include<iostream>
#include<vector>

using namespace std;

bool verify(vector<int> &tmpArray) {
//
//	if(tmpArray[tmpArray.size() - 2] < tmpArray[tmpArray.size() - 1]  && tmpArray[tmpArray.size()-3] < tmpArray[tmpArray.size() - 2]) return true;
//	else if(tmpArray[tmpArray.size() - 2] < tmpArray[tmpArray.size() - 1]  && tmpArray[tmpArray.size()-3] > tmpArray[tmpArray.size() - 2]) {
//		vector<int>::iterator itr = tmpArray.end();
//		tmpArray.erase(itr - 2);
//		return true;
//		}
//	else if(tmpArray[tmpArray.size() - 2] > tmpArray[tmpArray.size() - 1]  && tmpArray[tmpArray.size()-3] < tmpArray[tmpArray.size() - 2])
//		return true;
//	else if(tmpArray[tmpArray.size() - 2] < tmpArray[tmpArray.size() - 1]  && tmpArray[tmpArray.size()-3] > tmpArray[tmpArray.size() - 2]) {
//		vector<int>::iterator itr = tmpArray.end();
//		tmpArray.erase(itr);
//		return true;
//	}


	

}


void recursion(int *input, int start, int end, vector<int> &tmpArray, vector<vector<int>> &resultMatrix) {
	if(start >= end) {
		resultMatrix.push_back(tmpArray);
		return;
	}

	else {
		if( tmpArray.size() < 3) tmpArray.push_back(input[start]);

		else { if( (tmpArray[tmpArray.size() - 2] > tmpArray[tmpArray.size() - 1] && tmpArray[tmpArray.size() -1] > input[start+1]) || tmpArray[tmpArray.size()-1] > input[start] )
			tmpArray.push_back(input[start]);
		}
		recursion(input, start+1, end, tmpArray, resultMatrix); 

		if(tmpArray.size() >0) tmpArray.pop_back();
		recursion(input, 0, end, tmpArray, resultMatrix);

	
			
	}		

}

int main() {
	int input[] = {1, 11, 2, 10, 4, 5, 2, 1};
	int arraySize = sizeof(input) / sizeof(int);

	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

	recursion(input, 0, arraySize, tmpArray, resultMatrix);
	for(int i = 0; i < resultMatrix.size(); i++) {
		for(int j = 0; j < resultMatrix[i].size(); j++)
		cout << resultMatrix[i][j]<< " " ;
		cout << endl;
	}

}
