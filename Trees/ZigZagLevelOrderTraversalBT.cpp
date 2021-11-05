#include<iostream>
#include<vector>
#include<list>
#include<map>


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
//    			      9	 
//


node *parent = NULL, *grandParent = NULL;
vector<int> mylist[5];

int recursion(node *head,  int &height, multimap<int, int>  &resultArray) {
	if(head == NULL) { return 0; }	

	//out << height << endl;
	else {
	  	int l = recursion(head->left, height, resultArray) ;
		cout << "l = " << l << endl;
        	int r = recursion(head->right, height, resultArray) ;
		cout << "r = " << r << endl;
		if(l>r) {
		       resultArray.insert(std::pair<int, int>(l, head->data));
		       mylist[l].push_back(head->data);
	      		return	(l+1);
		}
		else 	{
		        resultArray.insert(std::pair<int, int>(r, head->data));
		       mylist[r].push_back(head->data);
			return (r+1);
		}

	
	}	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	head->right->right->left = new node(9);

	int  height = 0, sum=0;
	multimap<int, int> resultArray;

 	cout << "Height " << recursion(head, height, resultArray) << endl;

//	cout << "Final Total " << total << endl;



  for (int ch=0; ch<=3; ch++)
  {
    std::pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> ret;
    ret = resultArray.equal_range(ch);
    std::cout << ch << " =>";
    for (std::multimap<int,int>::iterator it=ret.first; it!=ret.second; ++it)
      std::cout << ' ' << it->second;
    std::cout << '\n';
  }


  for(int i =0; i < 5; i++){
	  for(int j =0; j < mylist[i].size(); j++)
		  cout << mylist[i][j] << " " ;

	  cout << endl;
  }
}
