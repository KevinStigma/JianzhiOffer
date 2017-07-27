class Solution {
public:
	void DFS(const string& str,string cur_str,vector<string>&results,vector<bool>& visited)
	{
		if(cur_str.length()==str.length())
		{
			results.push_back(cur_str);
			return;
		}
		
		for(int i=0;i<(int)str.length();i++)
		{
			if(visited[i]==false)
			{
				if(i!=0&&str[i]==str[i-1]&&visited[i-1]==false)
					continue;
				visited[i]=true;
				DFS(str,cur_str+str[i],results,visited);
				visited[i]=false;
			}
		}
	}
	
	vector<string> Permutation(string str) {
		vector<string> results;
		if(!str.length())
			return results;
		sort(str.begin(),str.end());
		vector<bool> visited(str.length(),false);
		DFS(str,"",results,visited);
		return results;
	}
};