#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

node *tmp = NULL, *startNode = NULL;

void recursion(node *head, node *currentNode) {
	if(!currentNode) {
	        while(head) {
        	        cout << head->val << endl;
                	head = head->next;
        	}

		return;
	}
	
	
	node *tmp = currentNode->next;
	currentNode->next = head;
	head = currentNode;

	recursion(head, tmp);

}

int main() {

        node *n = new node(1);
        n->next = new node(2);
        n->next->next = new node(3);
        n->next->next->next = new node(4);
        n->next->next->next->next = new node(5);

        n->next->next->next->next->next = new node(8);
        n->next->next->next->next->next->next = new node(9);

	node *currentNode = n->next;
	n->next = NULL;
	recursion(n, currentNode);

//	while(n) {
//		cout << n->val << endl;
//		n = n->next;
//	}
}
