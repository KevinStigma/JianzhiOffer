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
};