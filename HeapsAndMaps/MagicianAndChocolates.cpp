#include<iostream>
#include<set>
#include<map>

using namespace std;

void recursion(set<int> &myset, int start, int end, int &totalChocolates) {
	if(start >= end) return;

	set<int>::iterator itr = myset.end();
	itr--;
	
	int x = *itr;
	totalChocolates += x;
//	myset.insert(itr, (*itr)/2);
	myset.erase(itr);
	myset.insert(x/2);

	recursion(myset, start+1, end, totalChocolates);
}

int main() {
	set<int> myset{6,5};
	
	int k = 3, totalChocolates = 0;
	recursion(myset, 0, k, totalChocolates);
	cout << "Total Chocolates " << totalChocolates << endl;
 }
