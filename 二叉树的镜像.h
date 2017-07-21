struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void mirrorTree(TreeNode* root)
	{
		if(!root)
			return;
		TreeNode* left=root->left;
		TreeNode* right=root->right;
		root->left=right;
		root->right=left;
		mirrorTree(root->left);
		mirrorTree(root->right);
	}

	void Mirror(TreeNode *pRoot) 
	{
		if(pRoot==NULL)
			return;
		mirrorTree(pRoot);
    }
};