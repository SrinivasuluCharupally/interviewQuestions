#include<iostream>


using namespace std;


void recursion(string input, string &output, int index) {
	if(index <  0 ) { cout << output << endl; return; }

	int noOfChar = 0;	
	while(input[index] != ' ' && index >0 ) { index--; noOfChar++; }

	if(index >0 ) output  += input.substr(index+1, noOfChar);
	else output  += input.substr(0, noOfChar+1);

	output  += " ";
	recursion(input, output, index-1 );


}


int main() {
	string input = "the sky is blue";
	string output ;

	
	recursion(input, output, input.size()-1);
}
