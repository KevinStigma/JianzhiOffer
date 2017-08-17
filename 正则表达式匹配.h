class Solution {
public:
	bool matchCore(char*str,char*pattern,int sid,int pid)
	{
		if(str[sid]==pattern[pid]&&pattern[pid]==0)
			return true;
		if(pattern[pid]==0)
			return false;
		else if(str[sid]==0&&pattern[pid+1]!='*')
			return false;
		else if(str[sid]==0&&pattern[pid+1]=='*'&&pattern[pid+2]==0)
			return true;
		else if(str[sid]==0&&pattern[pid+1]=='*'&&pattern[pid+2]!=0)
			return false;
		if(pattern[pid+1]!='*'&&pattern[pid]!='.'&&pattern[pid]!=str[sid])
			return false;
		if(pattern[pid+1]!='*'&&((pattern[pid]!='.'&&pattern[pid]==str[sid])||(pattern[pid]=='.')))
			return matchCore(str,pattern,sid+1,pid+1);
		if(pattern[pid+1]=='*')
		{
			if(pattern[pid]!=str[sid]&&pattern[pid]!='.')
				return matchCore(str,pattern,sid,pid+2);
			else 
				return matchCore(str,pattern,sid,pid+2)||matchCore(str,pattern,sid+1,pid)||matchCore(str,pattern,sid+1,pid+2);
		}
		return true;
	}
	
	bool match(char* str, char* pattern)
	{
		if(!str||!pattern)
			return false;
		return matchCore(str,pattern,0,0);
	}
};