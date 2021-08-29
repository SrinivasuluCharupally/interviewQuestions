#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


int main() {
	int n = 4;
	for(int i = 0; i < pow(2,n) ; i++) {
		printf(" %d ", i ^ (i>>1));
	}
}

