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
	
  if(treehead->left) {
	treeNode *leftSub = treehead->left;
	while(leftSub->right)
		leftSub = leftSub->right;
	
	leftSub->right = treehead->right;
	treehead->right = treehead->left;
	treehead->left = NULL;
  } 

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

	while(head) {
		cout << head->data << " " ;
		head = head->right;
	}
	cout << endl;
}
