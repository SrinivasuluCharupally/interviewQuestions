#include<iostream>

using namespace std;

void recursion(int n, int &result) {
	if(n<=0) { cout << result << endl; return; }
	
	result = (result*10) + n %10 ;

	recursion(n/10, result);

}


int main() {
	int input = 123;
	int result = 0;
	recursion(input, result);
}

