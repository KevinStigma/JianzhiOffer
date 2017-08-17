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
	bool inOrder(TreeNode* root1,TreeNode* root2)
	{
		if(root1==NULL&&root2==NULL)
			return true;
		if(root1==NULL)
			return false;
		if(root2==NULL)
			return false;
		if(!inOrder(root1->left,root2->right))
			return false;
		if(root1->val!=root2->val)
			return false;
		if(!inOrder(root1->right,root2->left))
			return false;
		return true;
	}
	
    bool isSymmetrical(TreeNode* pRoot)
    {
		return inOrder(pRoot,pRoot);
    }
};