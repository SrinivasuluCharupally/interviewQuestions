#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *left, *right;
	node(int i) : data(i), left(NULL), right(NULL) {}
} node;

int findIndex(vector<int>& inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b] == val) {            return b; }
}

node* recursion(vector<int> &inOrder, vector<int> &postOrder, int i, int j, int poIndex) {
	if(i>j) return NULL;

	node *localnode = new node(postOrder[poIndex]);

	if ( i == j ) return localnode;

	int ioIndex = findIndex(inOrder, i, j, localnode->data);

	localnode->right = recursion(inOrder, postOrder, ioIndex+1, j , poIndex-1);

	localnode->left = recursion(inOrder, postOrder, i, ioIndex-1, poIndex-1);
	return localnode;

}

int main() {
	vector<int> postOrder = {2,3,1};
	vector<int> inOrder = {2,1,3};
	recursion(inOrder, postOrder, 0, inOrder.size()-1, postOrder.size()-1);
}
