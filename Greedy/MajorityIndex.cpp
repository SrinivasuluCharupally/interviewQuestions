#include<iostream>
#include<vector>

using namespace std;

void recursion(int *input, int start, int end, int &majorityElement, int &localCount) {
	if(start >= end) return;
	input[majorityElement] == input[start] ? ++localCount : --localCount;
	if(localCount == 0) {
		majorityElement = start;
		localCount = 1;
	}

	recursion(input, start+1, 6, majorityElement, localCount);
}

int main() {
	int input[] = {1,2,2,1,3,1};
	int localCount = 1;
	int majorityElement = 0;
	recursion(input, 1, 6, majorityElement, localCount);
	cout << "Majority Element " << input[majorityElement] << endl;
}
