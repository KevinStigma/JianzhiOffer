class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		unordered_map<int, int> counts;
		for (int i = 0; i<data.size(); i++)
		{
			if (counts.find(data[i]) == counts.end())
				counts[data[i]] = 1;
			else
				counts[data[i]]++;
		}
		int*p1=NULL, *p2 = NULL;
		for (int i = 0; i<data.size(); i++)
		{
			if (counts[data[i]] == 1 && !p1)
			{
				*num1 = data[i];
				p1 = &data[i];
			}
			else if (counts[data[i]] == 1 && !p2)
			{
				*num2 = data[i];
				p2 = &data[i];
			}
		}
	}
};