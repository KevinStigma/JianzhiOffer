struct RandomListNode 
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution 
{
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        unordered_map<RandomListNode*,RandomListNode*> maps;
		if(!pHead)
			return NULL;
		RandomListNode* head=new RandomListNode(pHead->label);
		RandomListNode* pt2=head;
		RandomListNode* pt=pHead;
		maps[NULL]=NULL;
		maps[pt]=pt2;
		while(pt->next)
		{
			RandomListNode* node=new RandomListNode(pt->next->label);
			pt2->next=node;
			pt2=pt2->next;
			pt=pt->next;
			maps[pt]=pt2;
		}
		
		pt=pHead;
		pt2=head;
		while(pt)
		{
			RandomListNode* ad=maps[pt->random];
			pt2->random=ad;
			pt=pt->next;
			pt2=pt2->next;
		}
		return head;
    }
};