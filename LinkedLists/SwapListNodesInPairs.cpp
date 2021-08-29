#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

node *tmp = NULL, *startNode = NULL;

void recursion(node *swapPosition, node *current, node *head, node *link) {
	if(!current) { 
		while(head) { 
			cout << head->val << endl;
			head = head->next; }
		cout << head->val ;			
		return;
	}
	

	node *tmpcurrent = current->next;
	node *tmpnext = current->next->next;

	current->next = swapPosition;
	swapPosition->next = tmpcurrent;

	if(head == NULL) head = current;
	if(!link) link = swapPosition;
	else { link->next = current;
		link = swapPosition;
	}
	

	recursion(tmpcurrent, tmpnext, head, link);

}

int main() {

        node *n = new node(1);
        n->next = new node(2);
        n->next->next = new node(3);
        n->next->next->next = new node(4);
        n->next->next->next->next = new node(5);

        n->next->next->next->next->next = new node(8);
        n->next->next->next->next->next->next = new node(9);
        n->next->next->next->next->next->next = new node(10);

	node *head = NULL, *link = NULL;

	recursion(n, n->next, head, link);

//	while(n) {
//		cout << n->val << endl;
//		n = n->next;
//	}
}
