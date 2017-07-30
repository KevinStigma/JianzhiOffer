class Solution {
public:
    int FirstNotRepeatingChar(string str) 
	{
		if(str.length()==0)
			return -1;
		vector<int> counts(126,0);
		vector<int> inds(126,-1);
		for(int i=0;i<(int)str.length();i++)
		{
			counts[int(str[i])]++;
			inds[int(str[i])]=i;
		}
		int min_ind=str.length();
		for(int i=0;i<126;i++)
		{
			if(counts[i]==1)
				min_ind=min(min_ind,inds[i]);
		}
		return min_ind;
    }
};