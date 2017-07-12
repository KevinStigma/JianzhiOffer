class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if(rotateArray.size()==0)
			return 0;
		if(rotateArray.size()==1)
			return rotateArray[0];
		int begin=0;
		int end=rotateArray.size()-1;
		int num=0;
		while(begin<=end)
		{
			int mid=(end+begin)/2;
			if(rotateArray[mid]>=rotateArray[0])
				begin=mid+1;
			else
			{
				end=mid-1;
				if(mid>0&&rotateArray[mid-1]>rotateArray[mid])
					return rotateArray[mid];
			}
			if(begin>end)
			{
				num=rotateArray[mid];
				break;
			}
		}
		return num;
	}
};