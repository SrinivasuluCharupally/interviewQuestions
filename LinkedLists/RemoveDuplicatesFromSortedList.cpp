#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) {}
} node;


void recusion(node *n) {
	if(!n) {
		return;
	}

	if(n->val == n->next->val) {
		
		n->next = n->next->next;
	}

	cout << n->val << " ";
	recusion(n->next);


}


int main() {
	node *n = new node(1);
	n->next = new node(1);
	n->next->next = new node(2);
	n->next->next->next = new node(3);
	n->next->next->next->next = new node(3);

	recusion(n);
}

