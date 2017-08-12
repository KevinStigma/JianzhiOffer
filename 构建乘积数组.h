class Solution {
public:
	vector<int> multiply(const vector<int>& A) 
	{
		vector<int> B(A.size());
		vector<int> D(A.size());
		vector<int> C(A.size());
		if(!A.size())
			return B;
		D[0]=1;
		C[A.size()-1]=1;
		for(int i=1;i<A.size();i++)
			D[i]=D[i-1]*A[i-1];
		for(int i=A.size()-2;i>=0;i--)
			C[i]=C[i+1]*A[i+1];
		for(int i=0;i<A.size();i++)
			B[i]=D[i]*C[i];
		return B;
	}
};