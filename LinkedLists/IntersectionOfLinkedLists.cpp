#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next;
	node (int i) : val(i), next(NULL) {}
}node;

int len(node *n) {
	if(n == NULL) 0;
	int l = 0;
	while(n != NULL){
		l +=1;
		n = n->next;
	}

	return l;
}



int main() {
	node *n1 = new node(1);
	n1->next = new node(2);
	n1->next->next = new node(3);
	n1->next->next->next = new node(4);

	node *n2 = new node(11);
	n2->next = new node(12);
	n2->next->next = new node(13);
	n2->next->next->next = n1->next->next;


	int n1length = len(n1);
	int n2length = len(n2);
	cout << "n1 length " << n1length << endl;
	cout << "n2 length " << n2length << endl;

	int diff = abs(n1length - n2length);

	if(n1length - n2length >= 0 ) {
		while(diff) {
			n1 = n1->next;
			diff--;
		}
	}
	else {

		while(diff) {
			n2 = n2->next;
			diff--;
		}
	}


	while(n1 != n2) {
		n1 = n1->next;
		n2 = n2->next;
	}



	cout << "intersecting point n1 = " << n1 << " n2 =  " << n2 << endl;
	cout << "data " << n1->val << " " << n2->val << endl;

}
