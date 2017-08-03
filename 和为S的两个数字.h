class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum)
	{
		vector<int> results;
		if(array.size()==0||array.size()==1)
			return results;
		int low=0,high=array.size()-1;
		int max_mult=0;
		while(low<high)
		{
			if(array[low]+array[high]>sum)
				high--;
			else if(array[low]+array[high]<sum)
				low++;
			else
			{
				if(!results.size())
				{
					results.push_back(array[low]);
					results.push_back(array[high]);
					max_mult=array[low]*array[high];
				}
				else
				{
					if(max_mult>array[low]*array[high])
					{
						results.clear();
						results.push_back(array[low]);
						results.push_back(array[high]);
						max_mult=array[low]*array[high];
					}
				}
				high--;
			}
		}
		return results;
	}
};