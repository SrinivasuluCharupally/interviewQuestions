#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) {}
} node;

void recursion(node *current, node * insertingPosition, int basevalue, node *previousNode) {
	if(current == NULL) return;

	if(current->val >=  basevalue && insertingPosition == NULL) {
		insertingPosition = previousNode;
	}


	if(insertingPosition != NULL && current->val < basevalue)  {
			previousNode->next = current->next;
			node *tmp = current;
			if(current->next !=NULL) current->next = insertingPosition->next;
			insertingPosition->next = current;
			insertingPosition = insertingPosition->next;
			current = previousNode;
	}

	recursion(current->next, insertingPosition, basevalue, previousNode->next);
	

}


int main() {
	node *n = new node(1);
	n->next = new node(4);
	n->next->next = new node(3);
	n->next->next->next = new node(2);
	n->next->next->next->next = new node(5);
	n->next->next->next->next->next = new node(2);


	int basevalue = 3;
	node *insertingPosition = NULL, *previousNode = n;
	recursion(n->next, insertingPosition, basevalue, previousNode);


}
