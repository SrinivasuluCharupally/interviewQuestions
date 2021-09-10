#include<iostream>
#include<vector>

using namespace std;

void recursion(string input, int &result, int index) {
	if(index >= input.size() ) { cout << result <<  endl; return; }

	result = result * 10 + (input[index] - 48);

	recursion(input, result, index+1);
}


int main() {
	string input = "123";
	int result = 0, index = 0;
	recursion(input, result, index);

	cout << "Add 3 to given number " << result+3 << endl;
}
