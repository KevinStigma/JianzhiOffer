class Solution {
public:
	void exportCircle(const vector<vector<int>>& matrix, vector<int>&list,int row,int col,int x,int y)
	{
		for(int i=0;i<col;i++)
			list.push_back(matrix[y][x+i]);
		for(int i=1;i<row;i++)
			list.push_back(matrix[y+i][x+col-1]);
		for(int i=1;i<col;i++)
			list.push_back(matrix[y+row-1][x+col-1-i]);
		for(int i=1;i<row-1;i++)
			list.push_back(matrix[y+row-1-i][x]);
	}
	
	vector<int> printMatrix(vector<vector<int>> matrix) 
	{
		vector<int> list;
		if(!matrix.size()||!matrix[0].size())
			return list;
		int rows=matrix.size();
		int cols=matrix[0].size();
		int cur_row=rows;
		int cur_col=cols;
		int cur_x=0,cur_y=0;
		while(cur_row>0&&cur_col>0)
		{
			if(cur_row>2&&cur_col>=2)
			{
				exportCircle(matrix,list,cur_row,cur_col,cur_x,cur_y);
				cur_col-=2;
				cur_row-=2;
			}
			else
			{
				if(cur_col==1)
				{
					for(int i=0;i<cur_row;i++)
						list.push_back(matrix[cur_y+i][cur_x]);
				}
				else if(cur_row==2)
				{
					for(int i=0;i<cur_col;i++)
						list.push_back(matrix[cur_y][cur_x+i]);
					for(int i=0;i<cur_col;i++)
						list.push_back(matrix[cur_y+1][cur_x+cur_col-1-i]);
				}
				else if(cur_row==1)
				{
					for(int i=0;i<cur_col;i++)
						list.push_back(matrix[cur_y][cur_x+i]);
				}
				break;
			}
			cur_x++;
			cur_y++;
		}
		return list;
	}
};