class Solution {
public:
	double Power(double base, int exponent) {
		if(base==0.0)
			return 0.0;
		if(exponent==0.0)
			return 1.0;
		int abs_exp=exponent;
		if(abs_exp<0)
			abs_exp*=-1;
		double res=1.0;
		int num=0;
		int stride=1;
		double stride_val=base;
		while(num!=abs_exp)
		{
			if(num+stride>abs_exp)
			{
				stride=1;
				stride_val=base;
			}
			else
			{
				num += stride;
				res = res*stride_val;
				stride = stride * 2;
				stride_val *= stride_val;
			}
		}
		if(exponent<0)
			res=1.0/res;
		return res;
    }
};