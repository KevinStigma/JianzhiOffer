class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		//对于个位：weight>=1,则 round+1;weight==0则 round
		//对于其他位：weight>1, round*base+base; weight==1,round*base+former+1;weight==0,round*base
		if(n<1)
			return 0;
		int count=0;
		int base=1;
		int round=n;
		while(round>0)
		{
			int weight=round%10;
			round=round/10;
			count+=round*base;
			if(weight>1)
				count=count+base;
			else if(weight==1)
				count=count+(n%base)+1;
			base=base*10;
		}
		return count;
    }
	
	int power10N(int n)
	{
		int res=1;
		for(int i=0;i<n;i++)
			res*=10;
		return res;
	}

	int numberOf1(const char* num)
	{
		int l=strlen(num);
		int first=num[0]-'0';
		if (first==0&&l>1)
			return numberOf1(num+1);
		if((l==0)||(l==1&&first==0))
			return 0;
		else if(l==1&&first>0)
			return 1;
		std::string str="";
		for(int i=0;i<l-1;i++)
			str.push_back('9');
		if(num[0]-'0'==1)
		{
			return atoi(num+1)+1+numberOf1(str.c_str())+numberOf1(num+1);
		}
		else
		{
			int n1=power10N(l-1);
			return n1+numberOf1(num+1)+first*numberOf1(str.c_str());
		}
	}

	int NumberOf1Between1AndN_Solution2(int n)
	{
		std::stringstream ss;
		std::string str;
		ss<<n;
		ss>>str;
		return numberOf1(str.c_str());
	}
};