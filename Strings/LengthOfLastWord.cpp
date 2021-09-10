#include<iostream>
#include<vector>

using namespace std;

void recursion(string input, int index) {
	if(index < 0) return;
	
	if(input[index] == ' ') { cout << "length of last word " << input.size() - index-1 << endl; return ;}
	
	recursion(input, index-1);
}

int main() {
	string input = "Hello World is";
	int index=0;
	recursion(input, input.size()-1);
}
