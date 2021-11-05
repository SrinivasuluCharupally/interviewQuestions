#include<iostream>
#include<vector>
#include<climits>

#include<algorithm>

using namespace std;

int compare(void *a, void *b) {
	return *(int*)a - *(int*)b;

}


void recursion(vector<int> input, int start, int left, int right, int diff, int target, int &result) {
	if(left >= right) return;

	int sum = input[start] + input[left] + input[right];

	int newdiff = abs(sum-target);
	if(newdiff < diff) { result = sum; diff = newdiff; }

	if(sum > target) recursion(input, start, left, right-1, diff, target, result);
	else recursion(input, start, left+1, right, diff, target, result);

	recursion(input, start+1, start+2, input.size()-1, diff, target, result);

}

int main() {
	vector<int> input = {-1, 2, 1, -4}; // -4 -1 1 2

//	qsort(input, input.size(), sizeof(int), compare);
 	sort(input.begin(), input.end());

	int result = 0, diff = INT_MAX, target = 1;
	recursion(input, 0, 1, input.size()-1, diff, target, result);
	
	cout << "Closet to given tart " << result << endl;
}


