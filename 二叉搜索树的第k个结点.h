struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* inOrder(TreeNode* root,int& k)
	{
		if(k<1)
			return NULL;
		if(!root)
			return NULL;
		TreeNode* node=inOrder(root->left,k);
		if(node)
			return node;
		k--;
		if(k==0)
		{
			return root;
		}
		node=inOrder(root->right,k);
		if(node)
			return node;
		return NULL;
	}
	
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if(!pRoot)
			return NULL;
		if(k<=0)
			return NULL;
		return inOrder(pRoot,k);
	}
};