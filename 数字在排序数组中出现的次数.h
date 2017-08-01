class Solution {
public:
	int binarySearch(vector<int>data,int flag,int k)
	{
		if(flag==0&&data[0]==k)
			return 0;
		if(flag==1&&data.back()==k)
			return data.size()-1;
		int low=0;
		int high=data.size()-1;
		int mid;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(flag==0)
			{
				if(data[mid-1]!=k&&data[mid]==k)
					return mid;
				else if(data[mid]>=k)
					high=mid-1;
				else
					low=mid+1;
			}
			else if(flag==1)
			{
				if(data[mid+1]!=k&&data[mid]==k)
					return mid;
				else if(data[mid]<=k)
					low=mid+1;
				else 
					high=mid-1;
			}
		}
		return -1;
	}
	
	int GetNumberOfK(vector<int> data ,int k) 
	{
		if(!data.size())
			return 0;
		int low_ind=binarySearch(data,0,k);
		int high_ind=binarySearch(data,1,k);
		return (low_ind==-1||high_ind==-1)?0:(high_ind-low_ind+1);
	}
};