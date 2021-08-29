#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) {}
} node;

node *head = NULL, *previous=NULL, *start=NULL;

void recusion(node *n) {
	if(!n->next) {
		cout << n->val << endl;
		return;
	}

	start = NULL;
	while(n->val == n->next->val) {
//		if(!start) start = n;
		n = n->next;

	}

	if( (n->next->next != NULL) ) { 
		if(n->next->val != n->next->next->val) { 
		cout << n->next->val << " " ; recusion(n->next->next); } 
	}

	else recusion(n->next);


}


int main() {
	node *n = new node(1);
	n->next = new node(1);
	n->next->next = new node(2);
	n->next->next->next = new node(3);
	n->next->next->next->next = new node(3);
	n->next->next->next->next->next = new node(4);
	n->next->next->next->next->next->next = new node(5);

	recusion(n);
}

