class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int>> results;
		if (sum <= 0)
			return results;
		int small = 1, big = 2;
		while (small<(sum / 2) + 1 && big != sum&&small<big)
		{
			int s = (big*(big + 1)) / 2 - (small*(small - 1)) / 2;
			if (s == sum)
			{
				vector<int> res;
				for (int i = small; i <= big; i++)
					res.push_back(i);
				results.push_back(res);
				big++;
			}
			else if (s<sum)
				big++;
			else
				small++;
		}
		return results;
	}
};