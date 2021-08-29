#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void recursion(vector<int> input, vector<int> &output, int index) {
	if(index >= input.size()) return;
	int i = index-1;

	for(; i >= 0; i--) {
		if(input[index] > input[i]) {
			output[index] = input[i];
			break;
		}
	}
//	if(i ==0) output[index] = -1;

	recursion(input, output, index+1);
	
}

int main() {
	vector<int> input = {3, 2, 1}; /*{4, 5, 2, 10};*/


	vector<int> output ={-1, -1, -1, -1};
	int index = 1;
	recursion(input, output, index);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << endl;
}
