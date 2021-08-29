#include<iostream>
#include<vector>

using namespace std;

void recursion (int *gasAtStation, int *gasRequired, int start, int end, int &startIndex, int &sumGas, int &sumCost, int &tank) {
	if(start >=end) return;
	sumGas += gasAtStation[start];
	sumCost += gasRequired[start];
	tank +=(gasAtStation[start] - gasRequired[start]);
	if(tank < 0) {
		startIndex = start+1;
		tank = 0;
	}

	recursion(gasAtStation, gasRequired, start+1, end, startIndex, sumGas, sumGas, tank);

}

int main() {
	int gasAtStation[] = {1,2};
	int gasRequired[] ={2,1};

	int sumGas=0, sumCost=0, tank=0, start=0, startIndex=0, end=2;
	recursion(gasAtStation, gasRequired, start, end, startIndex, sumGas, sumGas, tank);

	if(sumGas > sumCost) cout << "Min cost Index " << startIndex << endl;
	else cout << "Min cost Index not possible" << endl;




}
