#include<iostream>


using namespace std;

int RomanToInt(char c) {
	switch(c) {
		case 'M':
		case 'm':
			return 1000;
		case 'D':
		case 'd':
			return 500;
		case 'C':
		case 'c':
			return 100;
		case 'L':
		case 'l':
			return 50;
		case 'X':
		case 'x':
			return 10;
		case 'V':
		case 'v':
			return 5;
		case 'I':
		case 'i':
			return 1;
		default :
			return 0;
	}
}


void recursion(string input, int output, int index) {
	if(index >= input.size()) { cout << output << endl; return; }

	if(RomanToInt(input[index]) < RomanToInt(input[index+1]) ) {
		output -=  RomanToInt(input[index]);
	}
	else
		output += RomanToInt(input[index]);



	recursion(input, output, index+1);
}


int main() {
	string input = "XXIV";

	int output =0;

	recursion(input,output, 0);

}
