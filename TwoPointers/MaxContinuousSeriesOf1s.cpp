#include<iostream>
#include<vector>


using namespace std;

void recursion(vector<int> input, int &start, int &index, int &previouswindow, bool &flip) {
	if(index >= input.size()) return;

	int tmp=0;

	if(input[index] == 0 && flip == false) {
		flip = true;
		 tmp = index+1;

		while(input[index+1] != 0) {  index++; }
		index++;

	}

	else index++;

	if(previouswindow < (index-start)  && flip == true ) { 
		previouswindow = (index-start); 
		start = tmp; 
		flip = false; }
	else if(flip == true) { start = index; flip = false; }

	//index += 1;
	recursion(input, start, index, previouswindow, flip);
}


int main() {
	vector<int> input = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};

	int start = 0, index = 0, previouswindow = 0;
	bool flip = false;

	recursion(input, start, index, previouswindow, flip);

	cout << previouswindow << endl;
}


