class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int,int> visited;
		if(length<=0)
			return false;
		for(int i=0;i<length;i++)
		{
			if(visited.find(numbers[i])==visited.end())
				visited[numbers[i]]=1;
			else
			{
				*duplication=numbers[i];
				return true;
			}
		}
		return false;
    }
};