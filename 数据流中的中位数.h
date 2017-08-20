class Solution {
public:
	void Insert(int num)
	{
		if((gq.size()+lq.size())%2==0)
		{
			if(gq.size()+lq.size()==0||num<=lq.top())
				gq.push(num);
			else
			{
				int x=lq.top();
				lq.pop();
				gq.push(x);
				lq.push(num);
			}
		}
		else
		{
			if(num>=gq.top())
				lq.push(num);
			else
			{
				int x=gq.top();
				gq.pop();
				lq.push(x);
				gq.push(num);
			}
		}
	}
	double GetMedian()
	{
		if((gq.size()+lq.size())%2==1)
			return gq.top();
		else
			return double(gq.top()+lq.top())*0.5;
	}
	priority_queue<int> gq;
	priority_queue<int,vector<int>,greater<int>> lq;
};