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
	void DFS(TreeNode* root,int cur_sum,int expectNumber, vector<int>& path, vector<vector<int>>& res_paths)
	{
		cur_sum=cur_sum+root->val;
		path.push_back(root->val);
		if(!root->left&&!root->right&&cur_sum==expectNumber)
		{
			res_paths.push_back(path);
			
		}
		else
		{
			if(root->left)
				DFS(root->left,cur_sum,expectNumber,path,res_paths);
			if(root->right)
				DFS(root->right,cur_sum,expectNumber,path,res_paths);
		}
		path.pop_back();
	}
	
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
	{
		vector<vector<int>> paths;
		vector<int> path;
		if(!root)
			return paths;
		DFS(root,0,expectNumber,path,paths);
		return paths;
	}
};