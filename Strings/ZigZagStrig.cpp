#include<iostream>

using namespace std;

void recursion(string input, int index) {
	if(index  == input.size()) { cout << input << endl;  return; }

	int noOfcharToRemove = 0, start = index;
	while(input[index] == '.') { noOfcharToRemove++; index++; }

	if(noOfcharToRemove >0) input.erase(start, noOfcharToRemove);

	recursion(input, start+1);

}

int main() {
	string input = "P.......A........H.......N..A..P....L....S....I...I....G....Y.........I........R";

	recursion(input, 0);

}
