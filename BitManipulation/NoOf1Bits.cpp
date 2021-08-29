#include<iostream>

using namespace std;

void recusion(int input, int &noOfbits) {
	if(input >0) {
		noOfbits += input & 1;
		input = input >> 1;
		return recusion(input, noOfbits);
	}
	else return;
}


int main() {
	int input = 11, noOfbits = 0;
	recusion(input, noOfbits);
	printf("No of 1's in %d are : %d\n", input, noOfbits); 
}
