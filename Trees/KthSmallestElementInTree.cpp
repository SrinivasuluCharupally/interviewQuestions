// BST has to be sorted...
//
#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;

void recursion(node *head, int &smallest, int k, int &iteration) {
	if(head == NULL) return;

	recursion(head->left, smallest, k, iteration);
	++iteration;
	if(iteration == k) {
		smallest = head->data;
		return;
	}

	recursion(head->right, smallest, k, iteration);


}

void myprint(node *head) {
        if(head == NULL) return;

        cout << head->data << " " ;
        myprint(head->left);
        myprint(head->right);

}


int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);

	node *tmp = head;
	myprint(tmp);
	cout << endl;

	int smallest = 0, iteration=0, k = 2;
	recursion(head, smallest, k, iteration); 
	cout << "smallest "  << smallest << endl;
}
