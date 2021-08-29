#include<iostream>
#include<vector>

using namespace std;

int main() {
	int input[] = {0, 1, 2, 4, 5, 6, 7};
	int noOfPositionsRotate = 3;

	vector<int> tmp;
	int i = noOfPositionsRotate, k = noOfPositionsRotate; 
	while(i >= 0) {
		tmp.push_back(input[i]);
		i--;
	}

	int arraySize = sizeof(input)/sizeof(int);
	i = arraySize - noOfPositionsRotate-1;
	int index = 0;
	while(i > 0) {
		input[index] = input[index + noOfPositionsRotate +1];
		index++;
		i--;
	}

	i = noOfPositionsRotate;
	while( i >=0 ) {
		input[index] = tmp[i];
		index++;
		i--;
//		tmp.pop_back();
	}

	for(int j = 0; j < arraySize; j++)
		printf("%d ", input[j]);

//=============================================
// OTHER WAY OF USING, SINGLE WHILE LOOP
//===============================================
	int input1[] = {0, 1, 2, 4, 5, 6, 7};
	index = 0;
	vector<int> tmp1;
	i = 0;
	while(index < arraySize) {

		if(tmp1.size() <= noOfPositionsRotate+1) tmp1.push_back(input1[index]);
		if(index >= noOfPositionsRotate) {
			input1[index] = tmp1[i];
			i++;
		}
		else {

		input1[index] = input1[index+noOfPositionsRotate+1];
		}


		index++;
	}

	for(int j = 0; j < arraySize; j++)
		printf("%d ", input1[j]);
}
