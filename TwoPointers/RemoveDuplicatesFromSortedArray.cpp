#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> &input, int &index) {
	if(index >= input.size()) return;

	if(input[index - 1] == input[index]) 
		input.erase(input.begin()+index-1, input.begin()+index);

	index +=1;
	recursion(input, index);
}


int main() {
	vector<int> input = { 1,1,2,4,4};
	int index = 1;
	recursion(input, index); 

	for(int i = 0; i < input.size(); i++)
		cout << input[i];
	cout << endl;
}
