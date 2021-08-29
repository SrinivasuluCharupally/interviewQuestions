#include<iostream>

int fact(int n) {
	if(n<=0) return 1;
	else	 return n = (n) * (fact(n-1));
}

int main() {
	printf(" fact = %d ", fact(4));
}	
