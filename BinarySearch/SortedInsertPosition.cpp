#include<iostream>
#include<vector>

using namespace std;

void recursion(int *input, int start, int end, int *position, int targetValue) {
	if(start > end)  return;
	else {
		int mid = (start+end) / 2;
		int i = mid;
		if(input[i] == targetValue) {
			while(input[i] == targetValue) {position[1] = i; i++;}
			while(input[mid] == targetValue) { position[0] = mid; mid--;} 
			return;
		}
		else if(input[mid] < targetValue && input[mid+1] > targetValue) {
			position[0] = mid; position[1] = mid+1;
			return;
		}
		if(input[mid] > targetValue) recursion(input, start, mid, position, targetValue);
		if(input[mid] < targetValue) recursion(input, mid+1, end, position, targetValue);
	}
}

int main() {
	int input[] = {5, 7, 7, 8, 8, 10};
	int arraySize = sizeof(input) / sizeof(int);

	int position[2] ={0};
	int start=0, end=arraySize, targetValue=6;
	recursion(input, start, end, position, targetValue);
	printf("in between start at = %d, end at = %d ", position[0], position[1]);
	printf("\ninsert Position at = %d \n", position[1]);

}
