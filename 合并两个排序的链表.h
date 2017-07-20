struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* big_pt,*small_pt;
		if(pHead1==NULL)
			return pHead2;
		else if(pHead2==NULL)
			return pHead1;
		if(pHead1->val>pHead2->val)
		{
			big_pt=pHead1;
			small_pt=pHead2;
		}
		else
		{	
			big_pt=pHead2;
			small_pt=pHead1;
		}
		ListNode* first=small_pt;
		while(big_pt)
		{
			ListNode* p=small_pt;
			while(p->next!=NULL&&p->next->val<=big_pt->val)
				p=p->next;
			ListNode* next_pt=p->next;
			p->next=big_pt;
			small_pt=big_pt;
			big_pt=next_pt;
		}
		return first;
	}
};