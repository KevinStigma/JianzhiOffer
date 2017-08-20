class Solution {
public:
	bool DFS(char*matrix,int row,int col,int rows,int cols,char*str,int* visited,int id)
	{
		int index=row*cols+col;
		if(row>=rows||row<0||col>=cols||col<0||visited[index]||matrix[index]!=str[id])
			return false;
		visited[index]=1;
		if(str[id+1]==0)
			return true;
		return DFS(matrix,row+1,col,rows,cols,str,visited,id+1)||
		DFS(matrix,row-1,col,rows,cols,str,visited,id+1)||
		DFS(matrix,row,col+1,rows,cols,str,visited,id+1)||
		DFS(matrix,row,col-1,rows,cols,str,visited,id+1);
	}
	
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		int len=strlen(str);
		if(!matrix||!len||rows<=0||cols<=0)
			return false;
		int* visited=new int[rows*cols];
		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
			{
				if(matrix[i*cols+j]==str[0])
				{
					memset(visited,0,sizeof(int)*rows*cols);
					if(DFS(matrix,i,j,rows,cols,str,visited,0))
						return true;
				}
			}
		return false;
	}
};