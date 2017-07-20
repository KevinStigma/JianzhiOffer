struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if(pListHead==NULL||k<=0)
			return NULL;
		ListNode* forward=pListHead;
		for(int i=0;i<k-1;i++)
		{
			forward=forward->next;
			if(forward==NULL)
				return NULL;
		}
		ListNode* pt=pListHead;
		while(forward->next!=NULL)
		{
			forward=forward->next;
			pt=pt->next;
		}
		return pt;
	}
};