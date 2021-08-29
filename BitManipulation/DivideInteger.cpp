#include<iostream>
#include<vector>

using namespace std;

int main() {
	int divisor = 4;
	int divident = 12;
	int res = 0, count = 0;

	while(res+divisor <= divident) {
		res += divisor;
		count += 1;
	}

	printf(" %d / %d = %d \n", divident, divisor, count);
}


