#include<iostream>

using namespace std;

typedef struct node{
	int val;
	node *next;
	node(int i) : val(i), next(NULL) {} ;
} node;



void recustion(node *previous, node *current, bool & found) {
	if(!current->next) { 
		if(previous->val < current->val && found == false) {
		int tmp = current->val;
		current->val = 	previous->val;
		previous->val = tmp;
		found = true;
		}
		return;
	}

//	previous = current;
	recustion(previous->next, current->next, found);


}


int main() {
	node *n = new node(1);
	n->next = new node(2);
	n->next->next = new node(3);
	bool found = false;

	recustion(n, n->next, found);
	if(!found) { sort(n); };


	while(n) {
		cout << n->val;
		n = n->next;
	}
	cout << endl;
}
