#include<iostream>
#include<vector>

using namespace std;


void recursion(string v1, string v2, int start, int end) {
	if(start >= end)  return;
	int v11=0, v22=0, tmp = start;
	while(v1[start] != '.' && start < v1.size()) {
		v11 = (v11*10) + (v1[start] - 48);
		start += 1;
	}

	start = tmp;
	while(v2[start] != '.' && start < v2.size() ) {
		v22 = (v22*10) + (v2[start] - 48);
		start += 1;
	}

	if(v11 > v22) { cout << v1 << " is bigger than " << v2 << endl; }
	else if(v11 < v22) { cout << v1 << " is smaller than " << v2 << endl; }
	else if(v11 == v22) { recursion(v1, v2, start+1, end); }

}




int main() {
	string v1 = "1.13";
	string v2 = "1.13.4";


	
	v1.size() > v2.size() ? recursion(v1, v2, 0, v1.size()) : recursion(v2,v1, 0, v2.size());


}
