#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;
//
//		4	
//	2		5
//   1       3			6
//     
//



void recursion(node *head, int givenValue, int &sum, vector<int> &array) {
	if(head == NULL) return ;

	sum += head->data;
	array.push_back(head->data);

	if(sum == givenValue) {
		for(int i = 0; i < array.size(); i++) cout << array[i] << " " ;
		cout << endl;
	}


  	recursion(head->left, givenValue, sum, array);
	recursion(head->right, givenValue, sum, array);
	sum -= head->data;
	array.pop_back();
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	int givenValue = 6, sum=0;
	vector<int> array;
 	recursion(head, givenValue, sum, array);

}
