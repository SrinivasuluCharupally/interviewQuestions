#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




struct Compare
{
    bool operator()(ListNode* const& a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> &A) {
    if (A.empty())
        return NULL;
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    priority_queue<ListNode*, vector<ListNode*>, Compare> PQ;

    for (auto i = 0; i<A.size(); ++i)
    {
        if (A[i])
            PQ.emplace(A[i]);
    }

    while (!PQ.empty())
    {
        tail->next = PQ.top();
        PQ.pop();
        tail = tail->next;
        if (tail->next)
            PQ.emplace(tail->next);
    }
    return dummy->next;
}


int main() {
	ListNode *tmp ;
	ListNode *s1 = new ListNode(1);
	s1->next = new ListNode(10);
	s1->next->next = new ListNode(20);

//	ListNode *s1_head = s1;
//	s1->val = 1;
//	tmp = s1++;
//	s1->next = tmp;
//	s1->val = 10;
//	tmp = s1++;
//	s1->next = tmp;
//	s1->val = 20;
//	s1->next = NULL;

	ListNode *s2 = new ListNode(4);
	s2->next = new ListNode(11);
	s2->next->next = new ListNode(13);
	
	
	ListNode *s3 = new ListNode(3);
	s3->next = new ListNode(8);
	s3->next->next = new ListNode(9);
	
	
	
	//ListNode *s2 = new ListNode(4);
	//ListNode *s2_head = s2;
	//s2->val = 4;
	//s2->next = ++s2;
	//s2->val = 11;
	//s2->next = ++s2;
	//s2->val = 13;
	//s2->next = NULL;
	
//	ListNode *s3 = new ListNode(3);
//	ListNode *s3_head = s3;
//	s3->val = 3;
//	s3->next = ++s3;
//	s3->val = 8;
//	s3->next = ++s3;
//	s3->val = 9;
//	s3->next = NULL;
//

	vector<ListNode*> A{s1,s2,s3};
	ListNode *res = mergeKLists(A);

	while(res->next != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
	cout << res->val << endl;
}
