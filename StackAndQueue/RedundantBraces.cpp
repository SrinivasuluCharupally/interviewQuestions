#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void recursion(string &input, int index, stack<char> &mystack) {
	if(index >= input.size() ) {cout << " It does not have redundent braces" << endl; return; }
	
	char c = input[index];
	if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
		mystack.push(c);
	else if (c == ')') {
		if(mystack.top() == '(' ) {cout << " it has redundent braces" << endl; return; }
		else {
			while(! mystack.empty() && mystack.top() != '(' )
				mystack.pop();

			mystack.pop();
		}
	}

	recursion(input, index+1, mystack);


}

int main() {
	string input = /*"(a + (a + b))"; */ "((a+b))";

	int index = 0;
	stack<char> mystack;
	recursion(input, index, mystack);
}
