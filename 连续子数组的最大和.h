class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
	{
		if(!array.size())
			return 0;
		vector<int> dp(array.size(),0);
		dp[0]=array[0];
		int max_val=dp[0];
		for(int i=1;i<array.size();i++)
		{
			if(array[i]+dp[i-1]>array[i])
				dp[i]=array[i]+dp[i-1];
			else
				dp[i]=array[i];
			if(max_val<dp[i])
				max_val=dp[i];
		}
		return dp[i];
    }
};