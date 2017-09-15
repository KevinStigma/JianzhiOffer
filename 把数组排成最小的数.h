struct compare
{  
    bool operator() (const string &src1, const string &src2)  
    {  
        string s1 = src1 + src2;  
        string s2 = src2 + src1;  
        return s1 < s2;   
    }  
};  

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int i;  
		vector<string> strArray(numbers.size());  
  
		for(i = 0; i <numbers.size();i++)  
		{     
			stringstream stream;
			stream<<numbers[i];  
			stream>>strArray[i];  
		}  
		sort(strArray.begin(),strArray.end(),compare()); 
		string res="";
		for(i = 0; i < num; i++)
			res=res+strArray[i];    
		return res;
    }
};