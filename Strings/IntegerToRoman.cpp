#include<iostream>
#include<vector>


using namespace std;

void recursion(int input, string output, int i, int n[], string r[]) {
	if(input ==0) { cout << output << endl; return; }

	while(input >= n[i]) {
		output += r[i];
		input -= n[i];
	}

	recursion(input, output, i+1, n, r);
}

int main() {

    int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};   
    string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int input = 121;
    string output ;
    int counter=0;
    recursion(input, output, 0, n, r);

}
