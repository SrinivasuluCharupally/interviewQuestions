#include<iostream>
#include<vector>

using namespace std;

void recusion(int input, int &factor, int count) {
	if(count == input) { cout << factor << endl; return; }
	

	cout << factor << endl;
	factor *= (count+1);

	recusion(input, factor, count+1);

}



int main() {
	int input = 6;
	int factor = 1;
	recusion(input, factor, 1);
}
