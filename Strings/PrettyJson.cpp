#include<iostream>

using namespace std;

int tabs=0;

void recursion(string input, int index) {
	if(index < 0) return;

	recursion(input, index-1);

	if(input[index] == '{' ) { cout << endl << input[index] << endl; tabs++; int  tmp = tabs; while (tmp>0) { printf("\t"); tmp--; } }
	else if(input[index] == '}' ) { cout << endl << input[index] << endl; tabs--; }
	else if(input[index] == ',') {  cout << input[index] << endl; int  tmp = tabs; while (tmp>0) { printf("\t"); tmp--; } }
	else { int  tmp = tabs; while (tmp>0) { printf("\t"); tmp--; } cout << input[index] ; }

}




int main() {
	string input = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";

	int index = input.size()-1;

	recursion(input, index);
}
