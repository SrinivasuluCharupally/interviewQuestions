#include<iostream>
#include<vector>
#include<map>


using namespace std;

void recursion(vector<int> &input, int start, int end) {
	if(start >= end-2) return;

	map<int,int> mymap;
	for(int i = 0; i < 3; i++) {
		mymap[input[start+i]] += 1;
	}

	printf("%lu ", mymap.size());
	
	recursion(input, start+1, end);

}


int main() {
	vector<int> input {1, 2, 1, 3, 4, 3};
	recursion(input, 0, input.size());
	}
