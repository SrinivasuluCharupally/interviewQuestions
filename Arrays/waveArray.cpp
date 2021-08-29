#include<iostream>


int compare(const void  *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void swap(int &a, int &b){
	int tmp = b;
	b = a;
	a = tmp;
}

void wave(int *input) {
	for(int index = 0; index < 6 ; index += 2) {
		swap(input[index], input[index+1]);
	}
}

int main() {
	int input[6] = {3,4,5,6,1,0};
	int arraySize = sizeof(input) / sizeof(int);
	qsort(input, arraySize, sizeof(int), compare);
	for(int index = 0; index < arraySize; index++)
		printf(" %d ", input[index]);
	wave(input);
	
	printf("\nafter wave\n");
	for(int index = 0; index < arraySize; index++)
		printf(" %d ", input[index]);

}
