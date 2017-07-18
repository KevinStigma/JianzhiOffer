class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		priority_queue<int>q;
		vector<int> k_nums;
		if(k>input.size())
			return k_nums;
		
		for(int i=0;i<(int)input.size();i++)
		{
			if(q.size()<k)
				q.push(input[i]);
			else
			{
				if(q.top()>input[i])
				{
					q.pop();
					q.push(input[i]);
				}
			}
		}
		
		while(q.size())
		{
			k_nums.push_back(q.top());
			q.pop();
		}
		return k_nums;
    }
};