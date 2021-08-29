#include<iostream>

typedef struct range {
	int start=0, stop=0;
} range;
int main() {
	int input[9] {-2,1,-3,4,-1,2,1,-5,4};
	int arraySize = sizeof(input) / sizeof(int);
	int sum = 0, previousSum = 0;
	int rangesize = 0;
	range myrange{0,0}, previousrange{0,0};
	for(int index = 0; index < arraySize; index++) {
		sum += input[index] ; 
		myrange.stop = index;
		if( sum > previousSum) {
			previousSum = sum;
			if(myrange.stop - myrange.start >= rangesize) { 
			       previousrange = myrange;
			       rangesize = previousrange.stop - previousrange.start;
			}


		}
		if(sum <0) { 
			sum= 0 ;

			myrange.start = index+1;
			
		}
	}
	printf(" max sum %d, start index %d, stop index %d  ", previousSum , previousrange.start, previousrange.stop);

}

