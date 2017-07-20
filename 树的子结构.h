struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isEqual(TreeNode* root1,TreeNode* root2)
	{
		if(root2==NULL)
			return true;
		if(root1==NULL)
			return false;
		if(root1->val==root2->val)
		{
			if(isEqual(root1->left,root2->left)&&isEqual(root1->right,root2->right))
				return true;
		}
		return false;
	}
	
	bool hasSubTree(TreeNode* root1, TreeNode* root2)
	{
		if(root1==NULL)
			return false;
		if(isEqual(root1,root2))
			return true;
		if(hasSubTree(root1->left,root2)||hasSubTree(root1->right,root2))
			return true;
		return false;
	}
	
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if(pRoot2==NULL||pRoot1==NULL)
			return false;
		return hasSubTree(pRoot1,pRoot2);
	}
};