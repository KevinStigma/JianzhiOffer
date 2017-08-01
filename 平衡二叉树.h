class Solution {
public:
	int balancedDepth(TreeNode* root)
	{
		if(!root)
			return 0;
		int left_depth=balancedDepth(root->left);
		int right_depth=balancedDepth(root->right);
		if(left_depth>=0&&right_depth>=0&&abs(left_depth-right_depth)<=1)
			return max(left_depth,right_depth)+1;
		else
			return -1;
	}
	
	bool IsBalanced_Solution(TreeNode* pRoot) 
	{
		if(!pRoot)
			return true;
		int depth=balancedDepth(pRoot);
		if(depth>=0)
			return true;
		return false;
	}
};