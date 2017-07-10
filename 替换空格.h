class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(!str||length<=0)
			return;
		int blank_num=0;
		int ind=0;
		while(str[ind]!='\0')
		{
			if(str[ind]==' ')
				blank_num++;
			ind++;
		}
		int old_len=ind;
		int new_len=old_len+blank_num*2;
		if(new_len>length||(old_len==new_len))
			return;
		ind=old_len-1;
		while(ind>=0&&blank_num>0)
		{
			if(str[ind]==' ')
			{
				str[ind]='%';
				str[ind+1]='2';
				str[ind+2]='0';
				blank_num--;
			}
			else
				str[ind+2*blank_num]=str[ind];		
			ind--;
		}
	}
};