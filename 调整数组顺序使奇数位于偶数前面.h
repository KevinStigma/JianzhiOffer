class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> odds;
		vector<int> evens;
		for(int i=0;i<(int)array.size();i++)
		{
			if(array[i]%2==0)
				evens.push_back(array[i]);
			else
				odds.push_back(array[i]);
		}
		
		for(int i=0;i<(int)odds.size();i++)
			array[i]=odds[i];
		int base=odds.size();
		for(int i=0;i<(int)evens.size();i++)
			array[base+i]=evens[i];
	}
};