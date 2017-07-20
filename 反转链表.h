struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if(pHead==NULL||pHead->next==NULL)
			return pHead;
		ListNode* cur_pt=pHead->next;
		ListNode* first=pHead;
		while(cur_pt!=NULL)
		{
			pHead->next=cur_pt->next;
			cur_pt->next=first;
			first=cur_pt;
			cur_pt=pHead->next;
		}
		return first;
	}
};