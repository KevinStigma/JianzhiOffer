class Solution {
public:
	bool IsContinuous(vector<int> numbers) 
	{
		if(numbers.size()!=5)
			return false;
		sort(numbers.begin(),numbers.end());
		int max_num=numbers[4];
		int min_num=max_num;
		int w_count=0;
		for(int i=1;i<5;i++)
			if(numbers[i]!=0&&numbers[i]==numbers[i-1])
				return false;
		for(int i=0;i<5;i++)
		{
			if(numbers[i]!=0)
			{
				min_num=numbers[i];
				w_count=i;
				break;
			}
		}
		if(max_num==min_num)
			return true;
		if(max_num-min_num>4)
			return false;
		else 
			return true;
	}
};