#include<iostream>
#include<vector>
#include<map>

using namespace std;

typedef struct node {
	int value;
	node* nextNode=NULL;
	node* randNode=NULL;
} node;

void recursion(node *root, node *copy, map<int, node*> &mymap) {
	if(root == NULL) return;

	copy->value = root->value;
	mymap[copy->value] = copy;

	if(root->nextNode != NULL) {
		if(mymap.find(root->nextNode->value) != mymap.end() ) {
			copy->nextNode = mymap[root->nextNode->value];
		}
		else {
		node *next = new(node);
		next->value = root->nextNode->value;
		copy->nextNode = next;
		mymap[next->value] = next;
		}
	}
	if(root->randNode != NULL) {
		if(mymap.find(root->randNode->value) != mymap.end() ){
			copy->randNode = mymap[root->randNode->value];
		}
		else {
			node *rand = new(node);
			rand->value = root->randNode->value;
			copy->randNode = rand;
			mymap[root->randNode->value] = rand;
		}
	}
	recursion(root->nextNode, copy->nextNode, mymap);

}



int main() {
	node *root = new(node);
	node *r1 = new(node);
	node *r2 = new(node);
	root->value = 10; root->nextNode = r1; root->randNode = r2;
	r1->value = 20; r1->nextNode = r2; r1->randNode = root;
	r2->value = 30; r2->nextNode = NULL; r2->randNode = root;

	



	node *copy = new(node);
	map<int, node*> mymap;
	
	recursion(root, copy, mymap); 


	while(root != NULL) {
		cout << root->value << " " << root << " " << root->randNode << endl;
		root = root->nextNode;
	}
	cout << endl << "After Copy" << endl;

	while(copy != NULL) {
		cout << copy->value << " " << copy << " " << copy->randNode << endl;
		copy = copy->nextNode;
	}
}

