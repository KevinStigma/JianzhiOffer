class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.size()!=popV.size())
            return false;
        if(pushV.empty())
            return false;
        int push_ind=0,pop_ind=0;
        stack<int> s;
        while(1)
        {
            if(s.empty()||s.top()!=popV[pop_ind])
            {
                if(push_ind==pushV.size())
                    return false;
                s.push(pushV[push_ind]);
                push_ind++;
            }
            else if(push_ind==pushV.size()||s.top()==popV[pop_ind])
            {
                s.pop();
                pop_ind++;
            }
            if(pop_ind==popV.size()&&push_ind<pushV.size())
                return false;
            if(pop_ind==popV.size()&&push_ind==pushV.size())
                break;
        }
        if(s.empty())
            return true;
        return false;
    }
};