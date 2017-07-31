struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		unordered_map<ListNode*,int> maps;
		if(!pHead1||!pHead2)
			return NULL;
		ListNode* p=pHead1;
		while(p)
		{
			maps[p]=1;
			p=p->next;
		}
		p=pHead2;
		while(p)
		{
			if(maps.find(p)!=maps.end())
				return p;
			p=p->next;
		}
		return NULL;
    }
};