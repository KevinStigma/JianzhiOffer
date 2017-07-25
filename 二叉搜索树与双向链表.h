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
	typedef pair<TreeNode*,TreeNode*> TreeNodePair;
	
	TreeNodePair convertLink(TreeNode* root)
	{
		if(!root)
			return TreeNodePair(NULL,NULL);
		TreeNodePair res;
		if(!root->left)
			res.first=root;
		else
		{
			TreeNodePair pair=convertLink(root->left);
			res.first=pair.first;
			pair.second->right=root;
			root->left=pair.second;
		}
		if(!root->right)
			res.second=root;
		else
		{
			TreeNodePair pair=convertLink(root->right);
			res.second=pair.second;
			root->right=pair.first;
			pair.first->left=root;
		}
		return res;
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNodePair pair=convertLink(pRootOfTree);
		return 	pair.first;
	}
};