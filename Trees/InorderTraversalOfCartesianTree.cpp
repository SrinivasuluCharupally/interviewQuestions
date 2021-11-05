#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;


int maxVal(int i, int j, vector<int>& A)
{
    int maxi = i;
    for (auto p = i+1; p<=j; ++p)
        if (A[maxi]<A[p])
            maxi = p;
    return maxi;
}

node* recursion(vector<int> input, int i, int j) {
	if(i > j) return NULL;

	int index = maxVal(i, j, input);

	node *newNode = new node(input[index]);

	newNode->left = recursion(input, i, index-1);
	newNode->right = recursion(input, index+1, j);
	
	return newNode;

}

void myprint(node *head) {
	if(head == NULL) return;

	cout << head->data << " " ;
	myprint(head->left);
	myprint(head->right);

}
int main() {

	vector<int> input = {1,2,4, 3};
	node *head = recursion(input, 0, input.size()-1);

//	node * head = new node(1);
//	head->left = new node(2);
//	head->right = new node(3);
//	head->left->left = new node(4);
//	head->left->right = new node(5);
//	head->left->left->right = new node(4);
//

	myprint(head);
		
}
