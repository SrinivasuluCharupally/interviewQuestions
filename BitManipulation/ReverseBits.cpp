#include<iostream>

using namespace std;

void recusion(int input, unsigned int &result, int &totalbits) {
	if(input >0) {
		if(input & 1) {
			result |= (1 << (totalbits-1));
			totalbits = totalbits-1;
		}
		input = input >> 1;
		return recusion(input, result, totalbits);
	}
	else return;
}


int main() {
	int input = 3;
        unsigned int result = 0;
	int totalbits = sizeof(input)*8;

	recusion(input, result, totalbits);
	printf("No of 1's in %d are : %u\n", input, result); 
}
