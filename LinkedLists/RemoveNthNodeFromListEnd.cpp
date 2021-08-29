#include<iostream>

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



void recursion(node *n, int position, int localIndex) {
	if(localIndex >= position) { 
		n->next = n->next->next;
		return;
	}

	recursion(n->next, position, localIndex+1);
}

int main() {
	node *n = new node(1);
	n->next = new node(2);
	n->next->next = new node(3);
	n->next->next->next = new node(4);
	n->next->next->next->next = new node(5);

	n->next->next->next->next->next = new node(8);

	int l = length(n);
	cout << l << endl;
	int k = 2;
	recursion(n, l-k, 1) ;

	while(n) {
		cout << n->val << endl;
		n = n->next;
	}
}
