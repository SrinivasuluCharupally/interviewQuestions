#include<iostream>

using namespace std;

typedef struct node {
	int data;
	node *next = NULL;

	node(int i) : data(i), next(NULL) {}
} node;


// 2 3 5 4 1

void recursion(node *sorted, node *current, node *sortEnd) {
	if(current == NULL) {while(sorted) { cout << sorted->data; sorted = sorted->next;} return; }

	node *current_next = current->next;


	sortEnd->next = NULL;
	
	if( current->data < sorted->data) {
		current->next = sorted;
		sorted = current;
	}
	

	else {
		node *tmp = sorted;
		if(sortEnd->data < current->data) { sortEnd = current; sortEnd->next = NULL; }
		else { 
			while(tmp->next !=NULL &&  tmp->next->data < current->data) {
			tmp = tmp->next;
			}
		
//			current->next = tmp->next;
//			if(current->next == sortEnd) sortEnd = 
			current->next = tmp->next;
			tmp->next = current;
			
		}
	}
	


		
	return recursion(sorted, current_next, sortEnd);

}



int main() {
	node *n = new node(4);
	n->next = new node(1);
	n->next->next = new node(2);
	n->next->next->next = new node(0);

	node *sorted = n;
	node *current = n->next;
	sorted->next = NULL;
	recursion(sorted, current, sorted);

//	while(sorted) {
//		cout << sorted->data << endl;
//		sorted = sorted->next;
//	}
}


