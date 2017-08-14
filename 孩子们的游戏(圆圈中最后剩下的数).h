class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if(n < 1 || m < 1) return -1; 
		list<int> childs;
		for (int i = 0; i<n; i++)
			childs.push_back(i);
		auto it = childs.begin();
		while (childs.size() != 1)
		{
			for(int i=1;i<m;i++)
			{
				it++;
				if(it==childs.end())
					it=childs.begin();
			}
			auto tmp_it=it;
			it++;
			if(it==childs.end())
				it=childs.begin();
			childs.erase(tmp_it);
		}
		it = childs.begin();
		return *it;
	}
};