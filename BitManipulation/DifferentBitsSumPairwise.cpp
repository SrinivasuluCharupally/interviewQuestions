#include<iostream>
#include<vector>

using namespace std;

int sumFunc(int first, int second) {
	int x = first ^ second;
	int count = 0;
	while( x > 0 ) {
		count += (x & 1);
       		x = x>>1;	
	}
	return count;
}


int recursion(int *input, int start, int end, int &sum, int first, int startposition) {
	if(start >= end) return 0;
	if(startposition >= end) return 1;

	sum += sumFunc(first, input[start]);
	printf("start = %d , end = %d , sum = %d \n", first, input[start] , sum); 
	if(recursion(input, start+1, end, sum, first, startposition) == 1) return 1;
	first = input[startposition+1];
	recursion(input, 0, end, sum, first, startposition+1);
}


int main() {
	int input[] ={1,3,5};
	int arraySize = sizeof(input) / sizeof(int);

	int sum = 0, start = 0, startposition=0;
	recursion(input, start, arraySize, sum, input[0], startposition);
	printf(" sum = %d \n", sum);
}
