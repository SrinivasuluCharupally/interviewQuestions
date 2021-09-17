#include<iostream>

using namespace std;


void recursion(int input) {
	if(input == 1) { cout << "it's 2^x number" << endl; return; }

	if(input %2 != 0) { cout << " Not a 2^x number " << endl; return; }
	else recursion(input/2);


}


int main() {
	int input = 128, input1=96;

	if(input %2 == 0) recursion(input);
	if(input1 %2 == 0) recursion(input1);

}
