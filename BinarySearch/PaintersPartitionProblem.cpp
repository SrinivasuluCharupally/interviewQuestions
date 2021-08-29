#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


void recursion(vector<int> &inputBoards, int currentBoard, int noOfPainters, int timeForeachUnit, int &totalTime) {
	if(currentBoard >= inputBoards.size()) return;

	else {
		int mymax=0;
		for(int i =currentBoard, counter=0; counter < noOfPainters; i++, counter++){
			mymax = max(mymax, inputBoards[i]);
		}
		printf("\n max = %d\n", mymax);
		totalTime += mymax*timeForeachUnit;
		recursion(inputBoards, currentBoard+noOfPainters, noOfPainters, timeForeachUnit, totalTime);
	}
}

int main() {
	vector<int> inputBoards = {1,10,1};
	int noOfPainters = 2;
	int timeForeachUnit = 5;
	int totalTime = 0, currentBoard=0;

	recursion(inputBoards, currentBoard, noOfPainters, timeForeachUnit, totalTime);

	printf("Total time = %d \n", totalTime);
}
