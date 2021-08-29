#include<iostream>
#include<string>

using namespace std;

void recursion(int input, string &output) {
	if(input == 0) { cout << output << endl; return; }

	if(input & 1) output.push_back('1');
	else output.push_back('0');

	input = input >>1;
	recursion(input, output);
}

int main() {
	int input = 10;
	string output;

	recursion(input, output) ;
}
