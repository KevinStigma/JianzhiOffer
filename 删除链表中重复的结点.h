struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if(!pHead)
			return NULL;
		ListNode* p1=pHead;
		ListNode* p2=pHead;
		ListNode* pre=new ListNode(0);
		ListNode* first=pre;
		pre->next=pHead;
		while(p1&&p1->next)
		{
			p2=p1;
			while(p2->next!=NULL&&p2->next->val==p1->val)
				p2=p2->next;
			if(p2==p1)
			{
				pre=p1;
				p1=p1->next;
			}
			else
			{
				pre->next=p2->next;
				p1=p2->next;
			}
		}
		ListNode* head=first->next;
		delete first;
		return head;
	}
};