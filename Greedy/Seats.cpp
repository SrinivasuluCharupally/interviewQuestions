#include<iostream>
#include<vector>
#include<map>

using namespace std;


int main() {
	int input[] = {0,0,0,0,1,0,0,1,1,0,0,0,1,1};

	map<int, int> mymap;
	int count = 0, maxindex = 0, index =0, maxcount = 0, noOfmoves=0;

	int n = sizeof(input) / sizeof(int);

	for(int i = 0; i < n; i++) {
		if(input[i] == 1 ) {
			if(input[i-1] == 1) {
				mymap[index] += 1;
				count++;
				//maxindex = maxindex > previous ? maxindex : previous;
			}
			else {
				mymap[i] =1;
				index = i;
				count = 1;
			}
		}
		if(count > maxcount) {
		       maxindex = index;
		       maxcount = count;
		}

	}

	map<int, int> :: iterator itr;
	for(itr = mymap.begin(); itr != mymap.end(); itr++) {
		if(itr->first != maxindex) {
			if(itr->first > maxindex) 
			noOfmoves += (abs(itr->first - (maxindex+maxcount)) ) * itr->second;
			else
			noOfmoves += (abs(itr->first - maxindex) ) * itr->second;
		}
	}

	cout << "Minimum moves = " << noOfmoves << endl;
}
	


			
