#include<iostream>
#include<string>

using namespace std;

void recursion(string &input, int start, int end) {
	if(start == end) return;

	char c = input[end];
	input[end] = input[start];
	input[start] = c;

	recursion(input, start+1, end-1);

}

int main() {
	string input = "abc";
	int end = input.size()-1, start = 0;
	
	recursion(input, start, end);
	cout << input << endl;

}
