#include<iostream>
#include<vector>

using namespace std;

void recusion(int *input, int start, int end, int &sum, vector<int> &tmpArray, vector<vector<int>> &resultArrays, int *range) {
	if(start > end) return;
	if(sum >= range[0] && sum <= range[1]){
		resultArrays.push_back(tmpArray);

		return;
	}
	

	else {
		tmpArray.push_back(input[start]);
		sum += input[start];

		if(tmpArray.back() == 0 || sum < range[1])  recusion(input, start+1, end, sum, tmpArray, resultArrays, range);
		if( sum < range[1] && tmpArray.back() != 0) recusion(input, start, end, sum, tmpArray, resultArrays, range);
		
		//if(sum > range[1]) {
		sum = sum - tmpArray[tmpArray.size() - 1];
		tmpArray.pop_back();
		//}
		recusion(input, start+1, end, sum, tmpArray, resultArrays, range);
	}

		

}



void recusion2(int *input, int start, int end, int &sum, vector<int> &tmpArray, vector<vector<int>> &resultArrays, int *range) {
	if(start > end) return;

	

	else {
		tmpArray.push_back(input[start]);
		sum += input[start];

		if(sum >= range[0] && sum <= range[1]){
			resultArrays.push_back(tmpArray);
		}
		if(sum < range[1]) recusion2(input, start+1, end, sum, tmpArray, resultArrays, range);
	
		sum = sum - tmpArray[tmpArray.size() - 1];
		tmpArray.pop_back();
		recusion2(input, start+1, end, sum, tmpArray, resultArrays, range);
	}

		

}




int main() {
	int input[] = {10, 5, 1, 0, 2};
	int range[2] = {6,8};
	int arraySize = sizeof(input) / sizeof(int);

	vector<int>  tmpArray;
	vector<vector<int>> resultArrays;
	int sum = 0;

	recusion(input, 0, arraySize, sum, tmpArray, resultArrays, range);

	for(int i =0; i < resultArrays.size(); i++) {
		for(int j = 0; j < resultArrays[i].size(); j++)
			printf("%d, ", resultArrays[i][j]);
		cout << endl;
	}


	printf("Non repeating combinations\n");
        vector<int>  tmpArray2;
	vector<vector<int>> resultArrays2;
	int sum2 = 0;

	recusion2(input, 0, arraySize, sum2, tmpArray2, resultArrays2, range);

	for(int i =0; i < resultArrays.size(); i++) {
		for(int j = 0; j < resultArrays2[i].size(); j++)
			printf("%d, ", resultArrays2[i][j]);
		cout << endl;
	}
}

