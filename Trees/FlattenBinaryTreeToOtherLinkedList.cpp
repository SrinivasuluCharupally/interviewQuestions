#include<iostream>
#include<vector>

using namespace std;

typedef struct treeNode {
	int data;
	treeNode *right, *left;
	treeNode(int i) : data(i), left(NULL), right(NULL) {} 
} treeNode;

typedef struct mylist {
	int data;
	mylist *next;
	mylist(int i) : data(i), next(NULL) {}
} mylist;

mylist *headmylist = NULL;
mylist *currentPosition = NULL;

void recursion(treeNode *treehead) {
	if(treehead == NULL) 	return; 
	

	mylist *ls = new mylist(treehead->data);
	if(!headmylist)  { 
		headmylist = ls; 
	}
	else { currentPosition = headmylist;
	       while(currentPosition->next) currentPosition = currentPosition->next;
	       currentPosition->next = ls;
	} 

	recursion(treehead->left);
	recursion(treehead->right);	

}

int main() {
	treeNode * head = new treeNode(1);
	head->left = new treeNode(2);
	head->right = new treeNode(3);
	head->left->left = new treeNode(4);
	head->left->right = new treeNode(5);
	head->left->left->right = new treeNode(6);

	recursion(head);

	while(headmylist) {
		cout << headmylist->data << " " ;
		headmylist = headmylist->next;
	}
	cout << endl;
}
