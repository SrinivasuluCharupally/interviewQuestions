#include<iostream>
#include<vector>

using namespace std;

string checkPalindrom(string input, int index) {
	int left = index-1;
	int right = index+1;

	while(input[left] == input[right]) {
		left--;
		right++;
	}

	return input.substr(left+1, right-1);
}

void recursion(string input, string &currentSubString, string &previousSubString, int index) {
	if(index >= input.size()) { cout << previousSubString << endl; return; }
	
	currentSubString = checkPalindrom(input, index);
	if(currentSubString.size() > previousSubString.size()) previousSubString = currentSubString;

	recursion(input, currentSubString, previousSubString, index+1);
}

int main() {
	string input = "aaaabaaa";
	string currentSubString, previousSubString;
	int index = 1;
	recursion(input, currentSubString, previousSubString, index);
}
