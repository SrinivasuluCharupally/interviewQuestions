#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next;
	node(int i) : val(i),next(NULL) {}
} node;


void recursion(node *slow, node *fast ) {
	if(!fast->next || !fast->next->next) return;
	
	slow = slow->next;
	fast = fast->next->next;

	if(slow == fast) {
		while( slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		cout << "Looping node " << slow << " data " << slow->val << endl;
		
		return;
	}

	recursion(slow, fast);



}

int main() {
	node *n = new node (1);
	n->next = new node(2);
	n->next->next = new node(3);
	n->next->next->next = new node(4);
	n->next->next->next->next = n->next;



	cout << "fast = " << n->next->next->next->next << " slow " << n->next << endl;
	recursion(n, n);

}




