class Solution {
public:
	string LeftRotateString(string str, int n) 
	{
		if(str.length()==0||n<=0)
			return str;
		int len=str.length();
		int k=n%len;
		string top=str.substr(0,k);
		string tail=str.substr(k,str.length()-k);
		return tail+top;
	}
};