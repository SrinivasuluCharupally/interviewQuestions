#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

int length(node *n) {
	if(!n) return 0;
	int l=0;
	return (1+ length(n->next)) ;
}



void copyNodesToVector(node *runner, node *doubleRunner, vector<node*> &myvec) {
	if(!doubleRunner->next) { 
		runner = runner->next;
		while(runner) {
			myvec.push_back(runner);
			runner = runner->next;
		}
		       	return;
	}

	copyNodesToVector(runner->next, doubleRunner->next->next, myvec);
}

void mergeRightToLeft(node *n, vector<node*> &myvec) {
	if(myvec.size() <= 0) { n->next = NULL; return; }

	node *tmp = n->next;
	n->next = myvec[myvec.size()-1];
	n->next->next = tmp;
	myvec.pop_back();

	mergeRightToLeft(n->next->next, myvec);
}

int main() {
	node *n = new node(1);
	n->next = new node(2);
	n->next->next = new node(3);
	n->next->next->next = new node(4);
	n->next->next->next->next = new node(5);

	n->next->next->next->next->next = new node(8);
	n->next->next->next->next->next->next = new node(9);


	int l = length(n);
	vector<node*> myvec;

	copyNodesToVector(n,n, myvec);

	cout << "Length of the given list " << l << endl;
	int k = 2;



	mergeRightToLeft(n,myvec);
	while(n) {
		cout << n->val << endl;
		n = n->next;
	}
	cout << "top " << (myvec[myvec.size()-1])->val << endl;
}
