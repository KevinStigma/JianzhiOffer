class Solution {
public:	
    int GetUglyNumber_Solution(int index) {
		if(index<=0)
			return 0;
		vector<int> ugly_list;
		ugly_list.push_back(1);
		int ind2=0;
		int ind3=0;
		int ind5=0;
		while(ugly_list.size()!=index)
		{
			int max_num=ugly_list.back();
			while(ugly_list[ind2]*2<=max_num)
				ind2++;
			while(ugly_list[ind3]*3<=max_num)
				ind3++;
			while(ugly_list[ind5]*5<=max_num)
				ind5++;
			int num=min(ugly_list[ind2]*2,min(ugly_list[ind3]*3,ugly_list[ind5]*5));
			ugly_list.push_back(num);
		}
		return ugly_list.back();
	}
};