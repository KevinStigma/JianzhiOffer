struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if(!pRoot)
			return 0;
		int depth=0;
		depth=max(treeDepth(pRoot->left)+1, treeDepth(pRoot->right)+1);
		return depth;
	}
};