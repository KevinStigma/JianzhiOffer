class Solution {
public:
	bool isSequenceOfBST(vector<int>& seq,int begin,int end)
	{
		if(end-begin<=1)
			return true;
		int root_val=seq[end];
		int right_ind=-1;
		for(int i=begin;i<end;i++)
		{
			if(seq[i]>root_val)
			{
				right_ind=i;
				break;
			}
		}
		if(right_ind!=-1)
		{
			for(int i=right_ind;i<end;i++)
			{
				if(seq[i]<root_val)
					return false;
			}
		}
		
		if(right_ind==-1)
			return isSequenceOfBST(seq,begin,end-1);
		else
			return isSequenceOfBST(seq,begin,right_ind-1) && isSequenceOfBST(seq,right_ind,end-1);
		return true;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size()==0)
			return false;	
		return isSequenceOfBST(sequence,0,sequence.size()-1);
    }
};