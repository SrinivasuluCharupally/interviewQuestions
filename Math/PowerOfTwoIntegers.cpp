#include<iostream>

using namespace std;

void recursion(int small, int big, int &result) {
	if(small < 1) return;
	result *=big;
	recursion(small-1, big, result) ;
}

int main() {
	int small = 3, big = 4;

	if(small > big) { small = small * big; big = small / big; small = small / big; }
	int result = 1;

	recursion(small, big, result);

	cout << result << endl;
}
