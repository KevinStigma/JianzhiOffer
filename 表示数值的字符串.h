class Solution {
public:
	bool isNumeric(char* s)
	{
		string str(s);
		if(!str.length())
			return false;
		for(int i=0;i<str.length();i++)
		{
			if(!((str[i]>='0'&&str[i]<='9')||(str[i]=='e')||(str[i]=='E')||(str[i]=='.')||(str[i]=='+')||(str[i]=='-')))
				return false;
		}
		int e_ind=-1;
		int p_m_ind=-1;
		int dot_ind=-1;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='+'||str[i]=='-')
			{
				if(e_ind==-1&&i!=0)
					return false;
				else if(e_ind!=-1&&i!=e_ind+1)
					return false;
				p_m_ind=i;
			}
			if(str[i]=='e'||str[i]=='E')
			{
				if(i==0||i==str.length()-1)
					return false;
				if(e_ind!=-1)
					return false;
				e_ind=i;
			}
			if(str[i]=='.')
			{
				if(e_ind!=-1)
					return false;
				if(dot_ind!=-1)
					return false;
				dot_ind=i;
			}
		}
		return true;
	}
};