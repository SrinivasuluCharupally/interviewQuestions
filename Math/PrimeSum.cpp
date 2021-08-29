#include<iostream>
#include<cmath>

using namespace std;

bool  isPrime(int n) {

	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) { return false; }
	//cout << n << " is Prime" << endl;
	return true;
}


void recursion(int input, int guess) {
	if(input <2 ||  guess >= 10) return;

	if(isPrime(input-guess)  && isPrime(guess)) {
		cout << input-guess << " " << guess << endl;
	}


	recursion(input, guess+1);

}

int main() {
	int input = 10;
	recursion(input, 2);
}
