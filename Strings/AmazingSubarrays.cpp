#include<iostream>
#include<vector>


using namespace std;

bool isVowel(char c) {
	switch(c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
		break;
	default:
		return false;
	}
}
	
void recursion(string input, int index, int count) {
	if(index >= input.size()) { cout << "no.of magic strings " << count << endl; return; }
	
	if(isVowel(input[index]))  count += input.size() - index;

	recursion(input, index+1, count);

}

int main() {
	string input = "ABEC";
	int index = 0, count = 0;
	recursion(input, index, count);
}

