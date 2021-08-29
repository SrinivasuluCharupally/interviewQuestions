#include<iostream>

using namespace std;


typedef struct node {
	int data;
	node * next = NULL;
	node(int i) : data(i) , next{NULL} {}

} node;

node *head = NULL;

void recursion(node * n1, node* n2, node *res, int carry) {
	if(n1 == NULL || n2 == NULL) return;

	res->data =  n1->data + n2->data + carry;
	
	if(res->data >= 10) { carry = 1; res->data %= 10; }
	else carry = 0;

	if(head ==NULL) head = res;
	res->next = new node(0);

	recursion(n1->next, n2->next, res->next, carry);

}


int main() {
	node *n1 = new node(2);
	n1->next = new node(4);
	n1->next->next = new node(3);

	node *n2 = new node(5);
	n2->next = new node(6);
	n2->next->next = new node(4);

	node *res= new node(0);
	int carry=0;
	recursion(n1, n2, res, carry);
	
	while(head->next != NULL) {
		cout << head->data;
		head = head->next;
	}
	cout << endl;
}
