#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;


bool isPalindrome(const string s){

int i =0; int j = s.size()-1;

    while (i<j)
    {
        if (s[i] == s[j])
        {
            ++i; --j;
        }
        else
            return false;
    }
    return true;
}

void recursion(string str, int start, int end, string tempArray, vector<string> &resultMatrix) {
	if(tempArray.size() == 1) {
		return;
	}

	else {
		for(int i = 1; i <= str.size() - start;  i++){
			tempArray = str.substr(start, i);
			if(isPalindrome(tempArray)) {resultMatrix.push_back(tempArray); }
			recursion(tempArray, start+i-1, tempArray.size(), tempArray, resultMatrix);
		}
	}



}

int main() {
	string str = "aab";
	string  tempArray = "";
	vector<string> resultMatrix;
	int start=0, end=3; 

	recursion(str, start, end, tempArray, resultMatrix);

	for(int i =0; i < resultMatrix.size(); i++) {
		cout << resultMatrix[i] << endl;
	}
	return 0;
}
