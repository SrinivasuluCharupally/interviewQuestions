#include<iostream>
#include<vector>

using namespace std;

void recusion(int input,  int divisor) {
	if(divisor == input) { cout << divisor << endl; return; }
	



	recusion(input, divisor+1);
	if(input % divisor == 0) { cout << divisor << endl; }
//	factor *= (divisor+1);

}



int main() {
	int input = 8;
	int factor = 1;
	recusion(input,  1);
}
