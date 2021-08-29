#include<iostream>

int main() {
	int input[3]{1,3,-1};
	int arraySize = sizeof(input) / sizeof(int), max = 0, sum=0;
	for(int index = 0; index < arraySize; index++) {
		int mover = index;
		while( mover < arraySize ) {
			sum = abs(input[index] - input[mover]) + abs(mover - index);
			max = max > sum ? max : sum;
			mover++;
		}
	}
	printf("max value = %d \n", max);
return 0;
}
