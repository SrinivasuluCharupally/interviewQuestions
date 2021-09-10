#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<string> input, int charindex, int inputindex) {
	if(charindex >= input[0].size() || inputindex >= input.size()) return;

	if(input[0][charindex] == input[inputindex][charindex] ) {
		recursion(input, charindex, inputindex+1);
	}
	else { cout << "matching lengh " << charindex << endl; return; }

	recursion(input, charindex+1, 1);
}

int main() {
	vector<string> input = {   "abcdefgh",   "aefghijk",   "abcefgh" };

	int charindex = 0;

	recursion(input, charindex, 1);
}
