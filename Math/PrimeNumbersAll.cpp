#include<iostream>
#include<cmath>

using namespace std;

void isPrime(int n) {

	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) { cout << n << " not a prime" << endl; return; }
	cout << n << " is Prime" << endl;
}


void recursion(int input) {
	if(input <2) return;

	isPrime(input);
	recursion(input-1);
}

int main() {
	int input = 10;
	recursion(input);
}
