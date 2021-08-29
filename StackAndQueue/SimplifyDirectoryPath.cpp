#include<iostream>
#include<vector>
#include<stack>


using namespace std;

void recursion(string input, int index, stack<char> &mystack) {
	if(index-1 >= input.size() ) return;

	if(input[index] == '/' && input[index+1] != '/' && input[index+1] != '.') {
		mystack.push('/');
		index += 1;
	//	recursion(input, index+1);
	}
	else if(input[index] == '/' && input[index+1]  == '.' && input[index+2] == '/') {
		mystack.push('/');
		index += 3;
	//	recursion(input, index+2);
	}
	else if(input[index] == '.' && input[index+1] == '.' && input[index+2] == '/') {
		mystack.pop();
		index += 2;
	//	recursion(input, index+2);
	}
	else index += 1;

	recursion(input, index, mystack);

}


int main() {
	string input = "/a/./b/../../c/";
	stack<char>  mystack;
	int index=0;
	recursion(input, index, mystack);

	cout << mystack.size() << endl;
}
