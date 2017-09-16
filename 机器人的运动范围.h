class Solution {
public:
	int getDigitSum(int col,int row)
	{
		int sum=0;
		while(col)
		{
			sum+=(col%10);
			col=col/10;
		}
		while(row)
		{
			sum+=(row%10);
			row=row/10;
		}
		return sum;
	}
	void search(vector<vector<int>>& visited,int cur_row,int cur_col,int threshold,int rows,int cols,int& count)
	{
		if(cur_row>=rows||cur_col>=cols||cur_row<0||cur_col<0)
			return;
		if(visited[cur_row][cur_col])
			return;
		int sum=getDigitSum(cur_col,cur_row);
		if(sum>threshold)
		{
			visited[cur_row][cur_col]=1;
			return;
		}
		count++;
		visited[cur_row][cur_col]=1;
		search(visited,cur_row+1,cur_col,threshold,rows,cols,count);
		search(visited,cur_row-1,cur_col,threshold,rows,cols,count);
		search(visited,cur_row,cur_col+1,threshold,rows,cols,count);
		search(visited,cur_row,cur_col-1,threshold,rows,cols,count);
	}
	
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<1 || rows<1 || cols<1)
            return 0;
		vector<vector<int>> visited(rows);
		for(int i=0;i<rows;i++)
		{
			vector<int> v(cols);
			visited[i].assign(v.begin(),v.end());
		}
		int count=0;
		search(visited,0,0,threshold,rows,cols,count);
		return count;
    }
};