#include<iostream>
#include<vector>
#include<map>

using namespace std;

void recursion(vector<int> sumVector, map<int,int> mymap, int start, int end, int &seq_start, int &seq_max, int basePosition) {

	if(start >= end) { return; }

	if(abs(sumVector[basePosition] - sumVector[start]) == 0) { 
		if(abs(seq_max - seq_start) < abs(basePosition - start) ) {
			seq_max = start;
			seq_start = basePosition+1;
		}
	}

	recursion(sumVector, mymap, start+1, end, seq_start, seq_max, basePosition);
	recursion(sumVector, mymap, basePosition+2, end, seq_start, seq_max, basePosition+1);
}

int main() {
	int input[] = {1 ,2 ,-2 ,4 ,-4};
	int arraySize = sizeof(input) / sizeof(int);

	int sum=0;
	vector<int> sumVector;
	map<int, int> mymap;
	for(int i =0; i < arraySize; i++) {
		sum += input[i];
		sumVector.push_back(sum);
		mymap[sum] = i;
	}

	int seq_start =0, seq_max = 0;
	recursion(sumVector, mymap, 1, sumVector.size(), seq_start, seq_max, 0);

	for(int i =seq_start; i <= seq_max; i++){
		cout << input[i] << " ";
	}
	cout << endl;
}
