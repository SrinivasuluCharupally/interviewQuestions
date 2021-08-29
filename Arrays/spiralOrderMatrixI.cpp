#include<iostream>

//static bool traceback = false;
//static int x, y;

//void spiralOrder(int input[][4]) {
//	if( x > 3 || y > 3) return;
//	else {
//		printf("%d ", input[x][y]);
//		
//		if(!traceback) { y = y+1; spiralOrder(input); } else { x=x-1; spiralOrder(input); }
//		if(!traceback) { x = x+1; spiralOrder(input); } else { y=y-1; spiralOrder(input); }
//		if(!traceback && y != 4 && x != 4) traceback = true; else traceback = false;
//		//spiralOrder(input, x, y-1);
//		//spiralOrder(input, x-1, y);
//	}
//}	




//void spiralOrder(int input[][4], int x, int y) {
//	if( x > 3 || y > 3) return;
//	else {
//		printf("%d ", input[x][y]);
//		
//		if(!traceback) spiralOrder(input, x, y+1); else spiralOrder(input, x-1, y);
//		if(!traceback) spiralOrder(input, x+1, y); else spiralOrder(input, x, y-1);
//		if(!traceback) traceback = true; else traceback = false;
//		//spiralOrder(input, x, y-1);
//		//spiralOrder(input, x-1, y);
//	}
//}	

static int iR =0, jR=0;
static int sizeR = 4, sidesR=0;
static bool forwardR = true, downwardsR=false, backwardsR=false, upwardsR=false;
static int aR=0;


void spiralOrderWithRecursion(int input[][4]) {

	if(sidesR > (2*4)-1)  return;
	else {

//	for(int sides=0; sides < (2*4)-1; sides++) {
		if(forwardR) {
			for( int l =jR; l < sizeR-aR; l++) {
				printf(" %d ", input[iR][l]);
				jR = l;
			}
			forwardR = false; downwardsR = true;
		}
		else if(downwardsR) {
			for(int l =iR+1; l < sizeR-aR; l++) {
				printf(" %d ", input[l][jR]);
				iR=l;
			}
			downwardsR = false; backwardsR=true;
		}
		else if(backwardsR) { 
			for( int l=jR-1; l >= 0+aR; l--) {
				printf(" %d ", input[iR][l]);
				jR=l;
			}
			backwardsR=false; upwardsR=true;
		}
		else if(upwardsR) {
			for(int  l=iR-1; l > 0+aR; l--) {

				printf(" %d ", input[l][jR]);
				iR=l; //j=l;
			}
			jR=iR;
			upwardsR=false; forwardR=true;
			aR++;
		}
		//a++;
//		}
	sidesR = sidesR+1;
	spiralOrderWithRecursion(input);
	}
}

void spiralOrderWithoutRecursion(int input[][4]) {

int i =0, j=0;
int size = 4;
bool forward = true, downwards=false, backwards=false, upwards=false;
int a=0;
	for(int sides=0; sides < (2*4)-1; sides++) {
		if(forward) {
			for( int l =j; l < size-a; l++) {
				printf(" %d ", input[i][l]);
				j = l;
			}
			forward = false; downwards = true;
		}
		else if(downwards) {
			for(int l =i+1; l < size-a; l++) {
				printf(" %d ", input[l][j]);
				i=l;
			}
			downwards = false; backwards=true;
		}
		else if(backwards) { 
			for( int l=j-1; l >= 0+a; l--) {
				printf(" %d ", input[i][l]);
				j=l;
			}
			backwards=false; upwards=true;
		}
		else if(upwards) {
			for(int  l=i-1; l > 0+a; l--) {

				printf(" %d ", input[l][j]);
				i=l; //j=l;
			}
			j=i;
			upwards=false; forward=true;
			a++;
		}
		//a++;
	}
}



int main() {
	int input[][4] = 	{ {1, 2, 3, 4},
				  {12,13,14,5},
				  {11,16,15,6},
				  {10,9, 8, 7}};
	for(int i = 0; i < 4; i++) {
	       printf("\n");	
		for(int j=0; j < 4; j++) {
			printf(" %d\t",  input[i][j]);
		}
	}
	//x=0; y=0;
	printf(" \n Spiral without recursion \n");
	spiralOrderWithoutRecursion(input);

	printf(" \n Spiral with recursion \n");
	spiralOrderWithRecursion(input);
	
	printf(" \n ");
}

