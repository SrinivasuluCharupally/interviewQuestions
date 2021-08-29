#include<iostream>

using namespace std;

class base {
	void add(int i) {
		cout << "base" << endl;
	}
};

class deri : public base {
	void add(char c) {
		cout << "deri " << endl;
	}
};

int main() {
	base b;
}
