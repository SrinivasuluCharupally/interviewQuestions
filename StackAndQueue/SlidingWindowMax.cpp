#include<iostream>
#include<vector>
#include<set>

using namespace std;

void recursion(vector<int> input, set<int> &myset, int index) {
	if(index >= input.size() - 2) return;

	for(int i = index; i <= index+2; i++)
		myset.insert(input[i]);

	set<int>::iterator itr = myset.end();
	itr--;
	cout << *itr << endl;
	myset.clear();
	recursion(input, myset, index+1);

}

int main() {
	vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
	set<int> myset;
	int index = 0;

	recursion(input, myset, index);
}
