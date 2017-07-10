class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0||array[0].size()==0)
            return false;
		int m=array.size();
		int n=array[0].size();
        for(int i=0;i<m;i++)
        {	
			if(!(array[i][0]<=target&&array[i][n-1]>=target))
				continue;
			for(int j=0;j<n;j++)
				if(array[i][j]==target)
					return true;
        }
		return false;
    }
};