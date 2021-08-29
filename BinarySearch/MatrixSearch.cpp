// reference : https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/
//
#include<iostream>
#include<vector>

using namespace std;

int recursion(int input[][4], int x, int y, int targetSearch) {

	if(y >= 4) return 0;
	if(x >= 3 ) return 1;

		if(input[x][y] == targetSearch) {
			printf("\n1: found the element, x=%d , y=%d ", x,y);
//			return 1;
		}
		
		printf("x = %d , y = %d \n", x, y);
		if(recursion(input, x, y+1, targetSearch) ==1) return 1;
				
		return recursion(input, x+1, 0, targetSearch);
		
}


int recursion2(int input[][4], int x, int y, int targetSearch) {


	if(x >= 3 ) return 0;
	if(y >= 4) return 1;

	if(input[x][y] == targetSearch) {
			printf("\n2: found the element, x=%d , y=%d ", x,y);
			return 1;
	}
		
		if(recursion2(input, x+1, y, targetSearch) ==1) return 1;
		
		return recursion2(input, 0, y+1, targetSearch);
		
	
}

int main() {
	int input[][4] = { {1,   3,  5,  7},
			  {10, 11, 16, 20},
			  {23, 30, 34, 50}};

	for(int i =0; i < 3; i++) {
		for(int j=0; j < 4; j++)
			printf("%d  ", input[i][j]);
		printf("\n");
	}

	int x =0, y=0, targetSearch=16;
	recursion(input, x, y, targetSearch);

	recursion2(input, x, y, targetSearch);
}
