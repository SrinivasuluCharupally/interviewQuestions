#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>


using namespace std;

void recursion(string str, int start, int end, map<int,bool> &mymap, int currentIndex, int &mul) {
	if(start >= end || currentIndex >= end) return;

	else { 

//		string substr = str[upto];
		char s = str.at(currentIndex);
		mul *= stoi(&s);
		if(mymap.size() != 0) { 
			if(mymap.find(mul) != mymap.end()) {
			cout << "Found instance, not a ColorFul number" << endl;
			exit;
			return ; }
		}

		mymap[mul] = true;

		recursion(str, start, end, mymap, currentIndex+1, mul);

		mul = 1;
		recursion(str, start+1, end, mymap, start+1, mul);	
	}	
}

int main() {
	string str = "32452";
//	int size = sizeof(givenNumber) / sizeof(char);
	int size = str.length();

	map<int, bool> mymap;
	int currentIndex = 0, mul = 1;
	recursion(str, 0, size, mymap, currentIndex, mul);

	map<int, bool>::iterator itr;
	for(itr = mymap.begin(); itr != mymap.end(); itr++){
		cout << itr->first << " " << itr->second << endl;
	}
}
	

