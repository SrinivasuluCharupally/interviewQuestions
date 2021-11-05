#include<iostream>
#include<vector>

using namespace std;

typedef struct treeNode {
	int data;
	treeNode *right, *left;
	treeNode(int i) : data(i), left(NULL), right(NULL) {} 
} treeNode;



int recursion(treeNode *head_1, treeNode *head_2) {
	if(!head_1 || !head_2)  		return head_1 == head_2; 
	if(head_1->data != head_2->data) 	return 0;

	
	return recursion(head_1->left, head_2->left) && recursion(head_1->right, head_2->right);


}

int main() {
	treeNode * head_1 = new treeNode(1);
	head_1->left = new treeNode(2);
	head_1->right = new treeNode(3);
//	head_1->left->left = new treeNode(4);
//	head_1->left->right = new treeNode(5);
//	head_1->left->left->right = new treeNode(6);

        treeNode * head_2 = new treeNode(1);
        head_2->left = new treeNode(2);
        head_2->right = new treeNode(3);
//        head_2->left->left = new treeNode(4);
//        head_2->left->right = new treeNode(5);
//        head_2->left->left->right = new treeNode(6);
//


	cout << recursion(head_1, head_2) << endl;

//	while(head) {
//		cout << head->data << " " ;
//		head = head->right;
//	}
//	cout << endl;
}
