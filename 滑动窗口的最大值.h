class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		if(num.size()==0||num.size()<size||size<=0)
			return res;
		deque<int> q;
		for(int i=0;i<num.size();i++)
		{
			if(!q.empty()&&i-q.front()==size)
				q.pop_front();
			while(!q.empty()&&num[i]>=num[q.back()])
				q.pop_back();
			q.push_back(i);
			if(i>=size-1)
				res.push_back(num[q.front()]);
		}
		return res;
	}
};