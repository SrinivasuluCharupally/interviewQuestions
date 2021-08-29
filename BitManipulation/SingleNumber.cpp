#include<iostream>
#include<vector>

using namespace std;


int main() {
	int input[] = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
	int arraySize = sizeof(input) / sizeof(int);
	unsigned int result = 0, sum = 0;
	for(int i =0; i <  32; i++) {
		sum = 0;
		for(int j = 0; j < arraySize; j++) {
			if((input[j]>>i) & 1 == 1) 
				sum++;
				sum %= 3;
		}
		if(sum != 0)
			result |= sum << i;
	}
	printf(" not repeated number = %u ", result);

}


