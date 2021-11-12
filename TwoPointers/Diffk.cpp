#include<iostream>
#include<vector>
#include<climits>

#include<algorithm>

using namespace std;

int compare(void *a, void *b) {
	return *(int*)a - *(int*)b;

}


void recursion(vector<int> input, int left, int right, int target, int &result) {
	if(left >= right) return;

	if((target == input[right] - input[left])  && right != left) {
		result = 1;
		return;
	}

	if(target > input[right] - input[left]) recursion(input, left, right-1,  target, result);
	else recursion(input, left+1, right, target, result);
}

int main() {
	vector<int> input = {1,3,5}; // 

//	qsort(input, input.size(), sizeof(int), compare);
 	sort(input.begin(), input.end());

	int result = 0, diff = INT_MAX, target = 4;
	recursion(input, 0, input.size()-1, target, result);
	
	cout << "Closet to given tart " << result << endl;
}


