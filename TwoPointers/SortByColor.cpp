#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> input = {0, 1, 2, 0, 1, 2};

	sort(input.begin(), input.end());

	for(int i = 0; i < input.size(); i++)
		cout << input[i];

	cout << endl;
}
