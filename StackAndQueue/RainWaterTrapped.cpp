#include<iostream>
#include<vector>
#include<stack>


using namespace std;

void recursionTotal(vector<int> minVec, vector<int> maxVec, int &total, int counter, vector<int> input) {
	if(counter >= minVec.size()) return;

	total += ( minVec[counter] < maxVec[maxVec.size()-counter-1] ? minVec[counter] : maxVec[maxVec.size()-counter-1]) - input[counter] ;
	cout << minVec[counter] << " " << maxVec[maxVec.size()-counter-1] << " " << input[counter] << " " <<  total << endl;

	recursionTotal(minVec, maxVec, total, counter+1, input);
}


void recursion(vector<int> input, vector<int> &minVec, vector<int> &maxVec, int start, int end) {
	if(start >= input.size()) return;

	if(start == 0 ) { minVec.push_back(input[start]); maxVec.push_back(input[end]); }

	else { 
		minVec.push_back(minVec[minVec.size()-1] > input[start] ? minVec[minVec.size()-1] : input[start]);
		maxVec.push_back(input[end] < maxVec[maxVec.size()-1] ?  maxVec[maxVec.size()-1] : input[end]);
	}

	recursion(input, minVec, maxVec, start+1, end-1);
}


int main() {
	vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> minVec, maxVec;
	int start=0, end = input.size()-1;
	recursion(input, minVec, maxVec, start, end);
	int total = 0, counter=0;
	recursionTotal(minVec, maxVec, total, counter, input);
	cout << "Total " << total << endl;

}


