class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<1 || rows<1 || cols<1)
            return 0;
        else
            {
            bool* visited = new bool[rows*cols];
            memset(visited,0,rows*cols);
            int ncount =  movingCountcore(threshold,rows,cols,0,0,visited);
            delete[] visited;
            return ncount;
        }
             
    }
     
    int movingCountcore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int ncount=0;
        if(col>=0 && col<cols && row>=0 && row<rows && !visited[row*cols+col] && (getnum(col)+getnum(row))<=threshold)
            {
            visited[row*cols+col]=true;
            ncount++;
            ncount+=movingCountcore(threshold,rows,cols,row+1,col,visited);
            ncount+=movingCountcore(threshold,rows,cols,row-1,col,visited);
            ncount+=movingCountcore(threshold,rows,cols,row,col+1,visited);
            ncount+=movingCountcore(threshold,rows,cols,row,col-1,visited);
        }
        return ncount;
    }
    int getnum(int num)
        {
        int nvalue=0;
        while(num>0)
            {
            nvalue+=num%10;
            num/=10;
        }
        return nvalue;
    }
};