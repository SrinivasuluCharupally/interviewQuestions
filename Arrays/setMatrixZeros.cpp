#include<iostream>

void setZeros(int input[][4], int x, int y) {
	if(y<0 || x <0 ) return;

	else {
		if( input[x][y] ==0) {
			//printf(" \ninsize zero \n");
			for(int i = 0; i < 4; i++) {
				if( input[i][y] != 0 ) input[i][y] = -1;
			}
			for(int j = 0; j <4; j++){
				if( input[x][j] != 0) input[x][j] = -1;
			}
	
		}
		else {
			//printf(" x = %d , y = %d \n ", x, y);
			setZeros(input, x-1,y);
			setZeros(input, x, y-1);
			return;
		}
	}
}

int main() {
	int input[][4] = 	{ {1,3,4,0},
				  {2,4,5,1},
				  {0,1,4,4},
				  {1,3,4,5}};
	for(int i = 0; i < 4; i++) {
	       printf("\n");	
		for(int j=0; j < 4; j++) {
			printf(" %d ",  input[i][j]);
		}
	}

	setZeros(input, 3,3);

	printf("\nafter setting to zero");

	for(int i = 0; i < 4; i++) {
	       printf("\n");	
		for(int j=0; j < 4; j++) {
			printf(" %d ",  input[i][j]);
		}
	}

}

