#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;


void recursion(vector<string> &input, stack<int> &mystack, int index) {
	if(input.size() <= index) { cout << mystack.top() << endl; return; }

	if(input[index] == "+" || input[index] == "-" || input[index] == "*" || input[index] == "/" ) {
		if(!mystack.empty()) {
			int a = mystack.top(); mystack.pop();
			int b = mystack.top(); mystack.pop();

  			if(input[index] == "+") 	mystack.push(a+b);
			else if(input[index] == "-") 	mystack.push(a-b);
  			else if(input[index] == "*") 	mystack.push(a*b);
  			else if(input[index] == "/")    mystack.push(a/b);
  			
		}
	}

	else mystack.push(stoi(input[index]));

	recursion(input, mystack, index+1);


}

int main() {
	vector<string> input = {"2", "1", "+", "3", "*"};
	stack<int> mystack;
	int index = 0;
	recursion(input, mystack, index);
//	printf("%d \n" , '+');
//	printf("%d \n" , '-');
//	printf("%d \n" , '*');
//	printf("%d \n" , '/');
}
