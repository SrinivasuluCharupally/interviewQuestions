#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

node *tmp = NULL, *startNode = NULL;

void recursion(node *n, int start, int mystart, int myend) {
	if(start > myend) {
		startNode->next = tmp;
		while(tmp->next) { tmp = tmp->next; }
		tmp->next = n;	
		return;
	}
	
	node *current = n->next;
	if(start == mystart-1) startNode = n;

	if(start >= mystart && start <= myend) {
		if(!tmp) {tmp = n; tmp->next = NULL; }
		else { 
			node *localtmp = tmp;
			tmp = n;
			tmp->next = localtmp;
		}
	}

	recursion(current, start+1, mystart, myend);

}

int main() {

        node *n = new node(1);
        n->next = new node(2);
        n->next->next = new node(3);
        n->next->next->next = new node(4);
        n->next->next->next->next = new node(5);

        n->next->next->next->next->next = new node(8);
        n->next->next->next->next->next->next = new node(9);


	recursion(n, 1, 2, 4);

	while(n) {
		cout << n->val << endl;
		n = n->next;
	}
}
