class Solution {
public:
	//O(nlogk)
	vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
	{
		priority_queue<int>q;
		vector<int> k_nums;
		if(k<=0||k>input.size())
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
	
	int Partition(vector<int>&input,int start,int end)
	{
		if(start==end)
			return start;
		int num=input[start];
		int id=start;
		for(int i=start+1;i<=end;i++)
		{
			if(input[i]>num)
				continue;
			else
			{
				if(id+1!=i)
				{
					int tmp=input[id+1];
					input[id+1]=input[i];
					input[i]=tmp;
				}
				id++;
			}
		}
		
		int tmp = input[id];
		input[id] = input[start];
		input[start] = tmp;
		return id;
	}
	//O(n)
	vector<int> GetLeastNumbers_Solution2(vector<int>& input, int k)
	{
		vector<int> k_nums;
		if(k<=0||k>input.size())
			return k_nums;
		int begin=0;
		int end=input.size()-1;
		int id=Partition(input,begin,end);
		while(id!=k-1)
		{
			if(id>k-1)
			{
				end=id-1;
				id=Partition(input,begin,end);
			}
			else
			{
				begin=id+1;
				id=Partition(input,begin,end);
			}
		}
		for(int i=0;i<k;i++)
			k_nums.push_back(input[i]);
		return k_nums;
	}
	
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		return GetLeastNumbers_Solution2(input,k);
    }
};