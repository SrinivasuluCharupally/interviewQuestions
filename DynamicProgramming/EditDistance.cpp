#include<iostream>
#include<vector>

using namespace std;

void recursion(string s1, string s2, int s1_start, int s2_start, int l_big, int l_small) {
	if(s1_start >= l_big) return;
	else {
		if(s1[s1_start] == s2[s2_start])
			recursion(s1, s2, s1_start+1, s2_start+1, l_big, l_small);

		int diff = l_big - l_small;
		if(s1[s1_start] != s2[s2_start]) {
			cout << "replace " << s1[s1_start] << " with " <<  s2[s2_start] << endl;
			if(s1[s1_start+1] == s2[s2_start+diff+1] )
				cout << "insert "  <<  s2[s2_start+1] << endl;
				recursion(s1, s2, s1_start+1, s2_start+1+diff, l_big, l_small);
		

			
		}
	}	
}


int main() {
	string s1 = "Anshuman";
	string s2 = "Antihuman";

	int l_big = s1.length() > s2.length() ? s1.length() : s2.length();
	int l_small = s1.length() < s2.length() ? s1.length() : s2.length();

	int s1_start = 0, s2_start = 0;
	recursion(s1, s2, s1_start, s2_start, l_big, l_small);
}
