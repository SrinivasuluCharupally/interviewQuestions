#include<iostream>
#include<vector>
#include<string>

using namespace std;

void recursion(int input, int open, int close, string tempstring, vector<string> &resultMatrix ) {
	if(close == input) {
		resultMatrix.push_back(tempstring);
		return;
	}

	else {
		if(open < input ) { 
			tempstring += '{';
			recursion(input, open+1, close, tempstring, resultMatrix);
			tempstring.pop_back();
		}
		if(open > close) {
			tempstring += '}';
			recursion(input, open, close+1, tempstring, resultMatrix);
			tempstring.pop_back();
		}
	}
}

int main() {
	int input = 2, open = 0, close = 0;
	string tempstring;
	vector<string> resultMatrix;

	recursion(input, open, close, tempstring, resultMatrix);

	for(int i = 0; i < resultMatrix.size(); i++) {
		cout << resultMatrix[i] << endl;
//		printf("\n %s \n",  (char*) (resultMatrix[i]));
	}

}	
