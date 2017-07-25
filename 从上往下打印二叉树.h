struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> list;
        if(!root)
            return list;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode* node=q.front();
            q.pop();
            list.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return list;
    }
};