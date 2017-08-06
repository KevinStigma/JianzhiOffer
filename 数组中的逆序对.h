class Solution {
public:
	void divConquer(vector<int>&data,int low,int high,int&count)
	{
		if(low>=high)
			return;
		int mid=(low+high)/2;
		divConquer(data,low,mid,count);
		divConquer(data,mid+1,high,count);
		vector<int> tmp(high-low+1);
		int lb=low,le=mid,hb=mid+1,he=high;
		int lp=le,hp=he,p=tmp.size()-1;
		while(lp>=lb&&hp>=hb)
		{
			if(data[lp]>data[hp])
			{
				count+=(hp-hb+1);
				count=count%1000000007;
				tmp[p]=data[lp];
				lp--;
			}
			else
			{
				tmp[p]=data[hp];
				hp--;
			}
			p--;
		}
		while(hp>=hb)
		{
			tmp[p]=data[hp];
			hp--;
			p--;
		}
		while(lp>=lb)
		{
			tmp[p]=data[lp];
			lp--;
			p--;
		}
		for(int i=low;i<=high;i++)
			data[i]=tmp[i-low];
		count=count%1000000007;
	}
	int InversePairs(vector<int> data)
	{
		int count=0;
		if(!data.size())
			return count;
		divConquer(data,0,data.size()-1,count);
		return count;
	}
};