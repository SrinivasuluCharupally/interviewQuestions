#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	vector<string> arrayOfString ={"cat", "dog", "god", "tca"};

	map<string, vector<int>> mymap;

	for(int i =0; i < arrayOfString.size(); i++) {
		string tmpstr = arrayOfString[i];
		sort(tmpstr.begin(), tmpstr.end());

		mymap[tmpstr].push_back(i+1);
	}

	map<string, vector<int>>::iterator itr = mymap.begin();
	for(; itr!=mymap.end(); itr++) {
		cout << itr->second[0] << itr->second[1] << endl;
	}
}
	

