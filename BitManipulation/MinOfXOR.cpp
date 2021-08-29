#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


void recursion(int *input, int start, int end, int &minvalue) {
	if(start+2 > end) return ;

	int xorvalue = input[start] ^ input[start+1];
	minvalue = min(minvalue, xorvalue);
	recursion(input, start+1, end, minvalue);
}



int recursion2(int *input, int start, int end, int &minvalue, int firstvalueposition) {
	if(start >= end) return 0;
	if(firstvalueposition >= end) return 1;

	if(firstvalueposition != start) {	
		int xorvalue = input[firstvalueposition] ^ input[start];
		minvalue = min(minvalue, xorvalue);
	}

	if(recursion2(input, start+1, end, minvalue, firstvalueposition) == 1) return 1;
	return recursion2(input, 0, end, minvalue, firstvalueposition+1);
	
}

int main() {
	int input[] = {0,4,7,9};
	int arraySize = sizeof(input) / sizeof(int);
	int min = INT8_MAX;

	recursion(input, 0, arraySize, min);
	printf(" min xor value = %d ", min);


	min = INT8_MAX;
	recursion2(input, 0, arraySize, min, 0);
	printf(" min xor value = %d ", min);

}
