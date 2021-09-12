#include<iostream>

using namespace std;


void recursion(string input1, string input2, int &in1, int &in2, int index) {
	if(index >= input1.size() &&  index >= input2.size()) { cout <<in1 << in2 << endl; return; }

	if(input1.size() > index) { in1 = (in1*10) + input1[index]-48; }
	 
	if(input2.size() > index) { in2 = (in2*10) + input2[index]-48; }

	recursion(input1, input2, in1, in2, index+1);
}

void recursionResult(int res, string resultString) {
	if(res <= 0) { cout << resultString << endl; return; }

	char c = (res%10 +48);
	res /= 10;
	recursionResult(res, resultString);
	cout << c ; 
}

int main() {
	string input1 = "12";
	string input2 = "10";
	string resultString;
	int in1=0, in2=0, index=0;
	recursion(input1, input2, in1, in2, index);

	int res = in1 * in2;

	recursionResult(res, resultString);
	cout << endl;

}
