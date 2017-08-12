class Solution {
public:
	int StrToInt(string str) {
		if(str.length()==0)
			return 0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]!='+'&&str[i]!='-'&&!(str[i]>='0'&&str[i]<='9'))
				return 0;
		}
		int minus=0;
		int id=0;
		if(str[0]=='-')
		{
			minus=1;
			id++;
		}
		else if(str[0]=='+')
			id++;
		int num=0;
		while(id<str.length())
		{
			num=num*10;
			num=num+str[id]-'0';
			id++;
		}
		if(minus)
			num=num*(-1);
		return num;
	}
};