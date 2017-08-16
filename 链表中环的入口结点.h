struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if(!pHead||!pHead->next||!pHead->next->next)
			return NULL;
		ListNode* fast,*slow;
		fast=slow=pHead;
		slow=slow->next;
		fast=fast->next->next;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
			if(fast==NULL)
				return NULL;
			fast=fast->next;
			if(slow==NULL||fast==NULL)
				return NULL;
		}
		fast=pHead;
		while(slow!=fast)
		{
			fast=fast->next;
			slow=slow->next;
		}
		return slow;
	}
};