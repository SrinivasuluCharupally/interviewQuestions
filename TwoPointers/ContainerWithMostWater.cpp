#include<iostream>
#include<vector>

// Histogram example
// https://github.com/cruxrebels/InterviewBit/blob/master/TwoPointers/ContainerWithMostWater.cpp
using namespace std;

void recursion(vector<int> input, int &start, int &end, int &water) {
	if(start > end) return;

	water = max(water, min(input[start], input[end]) * (end-start));

	if(input[start] < input[end]) { start +=1; recursion(input, start, end, water); }
	if(input[start] < input[end]) { end -=1;   recursion(input, start, end, water); }
	
}


int main() {
	vector<int> input = {1, 5, 4, 3};
	int water = 0, start = 0, end = input.size()-1;
	recursion(input, start, end, water);

	cout << "Max water level " << water << endl;
}
