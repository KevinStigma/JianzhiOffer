struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	void recursiveAccess(ListNode* p,std::vector<int>&list)
	{
		if(!p)
			return;
		recursiveAccess(p->next,list);
		list.push_back(p->val);
	}
    vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> list;
		if(!head)
			return list;
		recursiveAccess(head,list);
		return list;
		
		/*std::vector<int> list;
		if(!head)
			return list;
		std::stack<int> tmp_stack;
		ListNode* p=head;
		while(p!=NULL)
		{
			tmp_stack.push(p->val);
			p=p->next;
		}
		while(tmp_stack.size())
		{
			int val=tmp_stack.top();
			list.push_back(val);
			tmp_stack.pop();
		}
		return list;
		*/
    }
};