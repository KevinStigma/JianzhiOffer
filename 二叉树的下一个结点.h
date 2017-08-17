struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if(!pNode)
			return NULL;
		if(pNode->right)
		{
			TreeLinkNode* node=pNode->right;
			if(!node->left)
				return node;
			while(node->left)
				node=node->left;
			return node;
		}
		else
		{
			TreeLinkNode* child=pNode;
			TreeLinkNode* parent=pNode->next;
			while(parent)
			{
				if(parent->left==child)
					return parent;
				child=parent;
				parent=child->next;
			}
			return NULL;
		}
	}
};