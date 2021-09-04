#include<iostream>
#include<string>

using namespace std;


void recursion(string a, string b, string &result, int index, int max, int cary) {
	if(index > max) {if (cary == 1) result +='1'; return; }
	int i, j;
if(a[index] != 48) {  i = a[index] - 48; } 
else {  i =0; }

if(b[index] != '\000') {  j = b[index]-48; } 
else {  j = 0; }

	if(i+j+cary == 3) {result += '1'; cary = 1; }
	else if(i+j+cary == 2) { result += '0'; cary = 1; }
	else if(i+j+cary == 1) { result += '0'; cary = 0; }
	
	recursion(a,b, result, index+1, max, cary);

}


int main() {
	string a = "101", b = "11";

	string result;
	int cary = 0;
	int max = a.size() > b.size() ? a.size() : b.size();
	int index = 0;
	recursion(a, b, result, index, max, cary);

	cout << result << endl;
}

