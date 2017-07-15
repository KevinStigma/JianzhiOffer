class Solution {
public:
	int rectCover(int number) {
		std::vector<int> dp(number+1);
		if(number==0||number==1||number==2)
			return number;
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=number;i++)
			dp[i]=dp[i-1]+dp[i-2];
		return dp[number];
	}
};