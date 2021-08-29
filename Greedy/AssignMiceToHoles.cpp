#include<iostream>
#include<vector>

using namespace std;

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void recursion( int *mice, int *hole, int start, int miceArraySize, int &time) {
	if(start >= miceArraySize) return;
	else {
		time = abs((mice[start] - hole[start])) > time ? abs((mice[start] - hole[start])) : time;
		recursion(mice, hole, start+1, miceArraySize, time);
	}
}

int main() {

	int mice[] = { 4, -4, 2};
	int hole[] = {4,0,5};

	int miceArraySize = sizeof(mice) / sizeof(int);
	qsort(mice, miceArraySize, sizeof(int), compare);
	qsort(hole, miceArraySize, sizeof(int), compare);
	int time = 0, start = 0;

	recursion(mice, hole, start, miceArraySize, time);
	cout << "Max Time = " << time << endl;
}
