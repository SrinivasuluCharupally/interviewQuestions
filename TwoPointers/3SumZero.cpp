#include<iostream>
#include<vector>
#include<climits>

#include<algorithm>

// important / impartent
//
using namespace std;

int compare(void *a, void *b) {
	return *(int*)a - *(int*)b;

}

// 2 3 4
// 1 2 5
// 1 3 4
void recursion(vector<int> input, int &start, int left, int right, int diff, int target, int &result) {
	if(left >= right || start >= input.size()-2  ) return;

	int sum = input[start] + input[left] + input[right];
	cout << start << " " << left << " " << right << " " << sum << endl;

	if(sum == 0) { result = result+1;  recursion(input, start, left+1, right-1, diff, target, result);  }
	else if(sum > 0) { recursion(input, start, left, right-1, diff, target, result); }
	     else if( sum <0) { recursion(input, start, left+1, right, diff, target, result); }
	start +=1; // it should be global to update to the same memory, otherwise it will create too many frames, 16
	int next = start+1;
	return recursion(input, start, next, input.size()-1, diff, target, result);
 
}

int main() {
	vector<int> input = {-1, 0, 1, 2, -1, -4}; // -4 -1 1 2

 	sort(input.begin(), input.end());

	int result = 0, diff = INT_MAX, target = 1;
	int start = 0;
	recursion(input, start, 1, input.size()-1, diff, target, result);
	
	cout << "Closet to given tart " << result << endl;
}


