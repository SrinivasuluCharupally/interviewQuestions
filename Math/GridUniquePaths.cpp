#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int x, y;
} node;

void recusion(int x, int y, int xPosition, int yPosition, vector<vector<node>> &resultMatrix, vector<node> &tmpvec) {

	if(xPosition == x-1 && yPosition == y-1) resultMatrix.push_back(tmpvec);

	if(xPosition >= x ||  yPosition >= y) return;
	
	node n = {xPosition, yPosition};

	tmpvec.push_back(n);

	recusion(x,y, xPosition+1, yPosition, resultMatrix, tmpvec);
//	tmpvec.pop_back();

	recusion(x,y, xPosition, yPosition+1, resultMatrix, tmpvec);


}


int main() {
	int x=2, y=2;
	vector<vector<node>> resultMatrix;
	vector<node> tmpvec;

	int xPosition = 0, yPosition=0;

	recusion(x,y, xPosition, yPosition, resultMatrix, tmpvec);

	cout << "No . of way for given matrix " << resultMatrix.size() << endl;

	for(int i =0; i < resultMatrix.size() ; i++) {
		for(int j = 0; j < resultMatrix[i].size(); j++) {
			cout << "(" << resultMatrix[i][j].x << ", " << resultMatrix[i][j].y << ")";
		}
		cout << endl;	
	}
}

