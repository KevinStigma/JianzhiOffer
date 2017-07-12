struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstruct(const vector<int>& pre,const vector<int>& vin,int pre_begin,int pre_end,int in_begin,int in_end)
	{
		if((pre_begin>pre_end)||(in_begin>in_end)||pre_begin<0||in_begin<0||pre_end>=pre.size()||in_end>=vin.size())
			return NULL;
		TreeNode* root=new TreeNode(pre[pre_begin]);
		int ind=in_begin;
		for(int i=in_begin;i<=in_end;i++)
		{
			if(vin[i]==pre[pre_begin])
			{
				ind=i;
				break;
			}
		}
		if(ind-1>=in_begin)
			root->left=reConstruct(pre,vin,pre_begin+1,pre_begin+ind-in_begin,in_begin,ind-1);
		if(ind+1<=in_end)
			root->right=reConstruct(pre,vin,pre_begin+ind-in_begin+1,pre_end,ind+1,in_end);
		return root;
	}
	
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) 
	{
		return reConstruct(pre,vin,0,pre.size()-1,0,vin.size()-1);
    }
};