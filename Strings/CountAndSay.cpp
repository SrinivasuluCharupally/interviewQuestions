#include<iostream>
#include<vector>

using namespace std;

void recursion(int input, string output) {
	if(input <= 0) { //cout << output << endl; 
		return; }

	int count=1;
	int lastdigit = input%10;
	input = input / 10;
	while(lastdigit == input %10) {
		count +=1;
		input /= 10;
	}

	output.push_back(count+48);
	output.push_back(lastdigit+48);

//	output += count+48;
//	output += lastdigit+48;

	recursion(input, output);
	cout << count << lastdigit ;
}


int main() {
	int input = 211;
	string output ;

	recursion(input, output);
}
