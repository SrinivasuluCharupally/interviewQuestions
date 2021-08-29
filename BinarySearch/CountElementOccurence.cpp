#include<iostream>
#include<vector>

using namespace std;

int compare(const void * a, const void *b) {
	return (*(int*)a - *(int*)b);
}

void recursion(int *input, int start, int end, int targetSum, int &noOfTimes ) {
	if(start > end) return;
	else {
		int mid = (start+end) / 2;
		if(targetSum > input[mid]) 
			recursion(input, mid, end, targetSum, noOfTimes);
		else if(targetSum < input[mid])
			recursion(input, start, mid, targetSum, noOfTimes);
	             else {
			//recursion(input, start+1, end, targetSum, noOfTimes);
			int positionUp =  mid+1, positionDown = mid-1;
			while(input[positionUp] == targetSum || (input[positionDown] == targetSum && positionDown >=0)) {
				if(input[positionUp] == targetSum) positionUp++;
				else if(input[positionDown] == targetSum || positionDown >=0) positionDown--;
				noOfTimes += 1;
			}
				noOfTimes++;
			return;
		     }
		return;
	}

}



int main() {
	int input[7] = { 5, 6,2,4,2,7,2};

	qsort(input, 7, sizeof(int), compare);

	for(int i=0; i < 7; i++) {
		printf("%d ", input[i]);
	}

	int start=0, end=7, noOfTimes=0, sum=2;
	recursion(input, start, end, sum, noOfTimes);
	
	printf("\n No of times the %d occurs = %d\n", sum, noOfTimes);
//	for(int i =0; i < 7; i++);
}
