#include<iostream>
#include<string>

using namespace std;


void recursion(int colomCounter, int requiredColoms ) {
	if(colomCounter == requiredColoms) return;


	printf("%d ", colomCounter);
	printf("\t %c" , (colomCounter / 26) + 64);
	printf("%c \n" , (colomCounter % 26) + 65);

	recursion(colomCounter+1,  requiredColoms);
}


int main() {
	int colomCounter=0;
	int requiredColoms = 201;

	recursion(colomCounter,  requiredColoms);
}
