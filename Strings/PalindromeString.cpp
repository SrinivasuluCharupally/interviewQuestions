#include<iostream>

using namespace std;

void recursion(string input, int indexLeft, int indexRight) {
	if(indexLeft == input.size()) { cout << "Is Palindrom" << endl;  return; }


	while (!isalpha(input[indexLeft]) )     { indexLeft++; }
	while (!isalpha(input[indexRight]))             { indexRight--; }


	if(tolower(input[indexLeft]) != tolower(input[indexRight])) 
		{ cout << "Not a Palindrom" << endl; return; }
	else 
		recursion(input, indexLeft+1, indexRight-1);

}

int main() {
	string input = "A man, a plan, a canal: Panama";

	int indexLeft = 0, indexRight = input.size()-1;

	if(input.size() % 2 == 0) recursion(input, indexLeft, indexRight);
}
