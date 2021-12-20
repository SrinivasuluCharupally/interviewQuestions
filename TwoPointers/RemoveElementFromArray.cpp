#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> &input, int &index, int elementToRemove) {
	if(index >= input.size()) return;

	if(input[index] == elementToRemove) { 
		input.erase(input.begin()+index, input.begin()+index+1);
	}
	else index +=1;
	recursion(input, index, elementToRemove);
}


int main() {
	vector<int> input = { 4, 1, 1, 2, 1, 3};
	int index = 0;
	int elementToRemove = 1;
	recursion(input, index, elementToRemove); 

	for(int i = 0; i < input.size(); i++)
		cout << input[i];
	cout << endl;
}
