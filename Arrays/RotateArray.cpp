#include<iostream>
#include<vector>

int main() {
	int input[6] = {1,2,3,4,5,6};
	int rotateBy = 3;
	int arrsize = sizeof(input) / sizeof(int);

	while(rotateBy >0) {
		int mover = input[0];
		for(int x=0; x< arrsize-1; x++) {
			input[x] = input[x+1];
		}
		input[arrsize-1] = mover;
		rotateBy = rotateBy - 1;
	}

#if 1	
	for(int x=0; x< arrsize; x++) {
		printf("%d  ", input[x] );
	}
#endif
	return 0;
}

	

		

