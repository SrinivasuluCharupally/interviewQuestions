#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<string> input, int allowedChar, int charCount, int index) {
	if(index >= input.size()) return;

	vector<string> tmpArray;
	while((charCount+input[index].size())  <= allowedChar) {
		charCount += input[index].size() + 1;
//		cout << input[index] << " " ;
		
		tmpArray.push_back(input[index]);

		index +=1;
	}
//	cout << endl;
	int noOfStrings = tmpArray.size();
	int noOfSpacesRequired = (allowedChar - charCount) / (noOfStrings == 1 ? noOfStrings : noOfStrings - 1);
	int tmpIndex = 0;
	while(tmpIndex < tmpArray.size()) {
		cout << tmpArray[tmpIndex];
		int i = 0;
		while(i < noOfSpacesRequired+1) {cout << " "; i++;}
		tmpIndex++;
	}
	cout << endl;
	charCount = 0; 
	recursion(input, allowedChar, charCount, index);
}

int main() {
	vector<string> input = {"This", "is", "an", "example", "of", "text", "justification"};
	int allowedChar=16, charCount=0, index=0;
	recursion(input, allowedChar, charCount, 0);
}
