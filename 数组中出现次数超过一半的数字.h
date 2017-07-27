class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		if(!numbers.size())
			return 0;
		unordered_map<int,int> maps;
		for(int i=0;i<(int)numbers.size();i++)
		{
			if(maps.find(numbers[i])==maps.end())
				maps[numbers[i]]=1;
			else
				maps[numbers[i]]++;
			if(maps[numbers[i]]>numbers.size()/2)
				return numbers[i];
		}
		return 0;
    }
};