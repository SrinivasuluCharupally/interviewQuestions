#include<iostream>

void merge(int *input, int start, int mid, int stop) {
	int i = start, j = mid+1, k=0;
	int temp[stop - start +1];

	while(i <= mid && j <= stop){
		if(input[i] <= input[j]) {
			temp[k] = input[i];
			i++;
		}
		else {
			temp[k] = input[j];
			j++;
		}
		++k;
	}

	while(i <= mid) {
		temp[k] = input[i];
		i++;
		k++;
	}

	while(j <= stop) {
		temp[k] = input[j];
		++j;
		++k;
	}

	for(i = start; i <= stop; i++) {
		input[i] = temp[i - start];
	}
}

void mergeSort(int *input, int start, int stop) {
	if(start < stop) {
		int mid = (start + stop) / 2;
		mergeSort(input, start, mid);
		mergeSort(input, mid+1, stop);
		merge(input, start, mid, stop);
	}
}

int main() {
	int input[5] = {4,2,1,6,3};
	int arraySize = sizeof(input) / sizeof(int);
	printf(" before sort ");
	for( int i = 0; i < arraySize; i++) {
		printf(" %d " , input[i]);
	}
	mergeSort(input, 0, arraySize-1);

	printf(" \nafter sort ");
	for( int i = 0; i < arraySize; i++) {
		printf(" %d " , input[i]);
	}
}
