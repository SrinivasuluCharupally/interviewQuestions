#include<iostream>
#include<vector>

int main() {
	int input[5]= {5,3,1,7,2};
	int arraySize = sizeof(input) / sizeof(int);
	for(int index = 0; index < arraySize; index++) {
		int key = input[index+1];
		int mover = index ; // 0
		while(mover >= 0  && key < input[mover]) {
			input[mover+1] = input[mover];
			mover -= 1;
		}
		input[mover+1]  = key;
	}
	for(int index = 0; index < arraySize; index++) 
		printf(" %d \n", input[index]);
}

