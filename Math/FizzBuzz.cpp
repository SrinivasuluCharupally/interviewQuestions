#include<iostream>

using namespace std;

void recursion(int input, int position) {
	if(position == input) return;
	
	if(position % 3 == 0 && position % 5 == 0) cout << "FizzBuzz" << endl;
	else if(position % 3 == 0) cout << "Fizz" << endl;
		else if(position % 5 == 0 ) cout << "Buzz" << endl;
		else cout << position << endl;

	recursion(input, position+1);


}

int main() {
	int input = 16, position = 1;

	recursion(input, position) ;

}
