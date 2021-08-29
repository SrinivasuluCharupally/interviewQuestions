#include<iostream>
#include<vector>

using namespace std;

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
//void recusion(int *input, int start, int end, int maxProduct) {
//	if(start >= end) return;
//	
//
//}


int main() {
	int input[] = {0, -1, 3, 100, 70, 50};

	qsort(input, 6, sizeof(int), compare);	
//	recusion(input, 0, 6, maxProduct);
//
	int maxpositive = input[5] * input[4] * input[3];
	int maxnegetive = input[0]*input[1]*input[5]; // -ve * -ve * +ve ===> result positive max

	if(maxpositive > maxnegetive) cout << maxpositive << endl;
	else cout << maxnegetive << endl;
}
