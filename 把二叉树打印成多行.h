class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> tree;
        if(!pRoot)
            return tree;
        queue<pair<TreeNode*,int>> q;
        q.push(pair<TreeNode*,int>(pRoot,0));
        while(q.size())
        {
            auto top=q.front();
            q.pop();
            TreeNode* cur_node=top.first;
            int val=cur_node->val;
            int dep=top.second;
            if(tree.size()<dep+1)
            {
                vector<int> layer{val};
                tree.push_back(layer);
            }
            else
                tree[dep].push_back(val);
            if(cur_node->left)
                q.push(pair<TreeNode*,int>(cur_node->left,dep+1));
            if(cur_node->right)
                q.push(pair<TreeNode*,int>(cur_node->right,dep+1));
        }
        return tree;
    }
     
};