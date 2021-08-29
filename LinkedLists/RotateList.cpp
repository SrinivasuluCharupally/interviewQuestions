#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

node *tmp = NULL, *startNode = NULL;

void recursion(node *current, int start, int mystart, node *head, node *previousNode) {
	if(!current)  {
		previousNode->next = NULL;

		while(head) { cout << head->val << endl;
				head = head->next ;
		}

		return;
	}
	

//	if(start == mystart-1) startNode = n;
	node *tmp = current->next;
	node *tmpprevious = previousNode;


	if(start >= mystart && current !=NULL ) {
			if(current->next !=NULL) { 
				previousNode->next = current->next;
			}
			current->next = head;
			head = current;
			
	}

	if(start >= mystart) recursion(tmp, start+1, mystart, head, tmpprevious);
	else recursion(tmp, start+1, mystart, head, previousNode->next);


}

int main() {

        node *n = new node(1);
        n->next = new node(2);
        n->next->next = new node(3);
        n->next->next->next = new node(4);
        n->next->next->next->next = new node(5);

        n->next->next->next->next->next = new node(8);
        n->next->next->next->next->next->next = new node(9);


	recursion(n->next, 2, 6, n, n);

//	while(n) {
//		cout << n->val << endl;
//		n = n->next;
//	}
}
