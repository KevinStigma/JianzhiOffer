class Solution
{
public:
	Solution()
	{
		memset(visited,0,sizeof(char)*256);
		ind=-1;
	}
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str.push_back(ch);
		visited[ch]++;
		if(str.length()==1)
			ind=0;
		else if(ind==-1)
		{
			if(visited[ch]==1)
				ind=str.length()-1;
		}
		else if(str[ind]==ch)
		{
			for(int i=ind+1;i<str.length();i++)
			{
				if(visited[str[i]]==1)
				{
					ind=i;
					return;
				}
			}
			ind=-1;
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if(ind==-1)
			return '#';
		return str[ind];
	}
	string str;
	int visited[256];
	int ind;
};