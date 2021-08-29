#include<iostream>
#include<vector>

using namespace std;

int main() {
	int input = 8;
	int rows = (input*2)-1, col = (input*2)-1;


	int result = 0;
	for(int i = 0; i < rows; i++) {
		int decrease = i, increase = rows-i, result = input;
		for(int j = 0, k = input; j < col; j++) {
			//int x = k - i;
			
			cout << result << " " ;

		if(i <= rows / 2) {
			if(j < col/2) {
				if(decrease > 0) { // 3 2 1
				result-- ;	// 3 2 1
				decrease--;	// 2 1 0 
				}
			}
			else { 
				if( j + i + 1 >= col ) {
				result++;
				}
			}

		}
		
		else {
			if(j < col / 2) {
				if( increase - 1 > 0) {
					result--;
					increase--;
				}
			}
			else {
				if( j - i+1  >  0) {
					result++;
				}
			}
		}
		}
		cout << endl;
	}
}
