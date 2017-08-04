class Solution {
public:
	string ReverseSentence(string str)
	{
		if(!str.length())
			return str;
		stack<string> list;
		stack<int> counts;
		int i = 0;
		int begin = -1, end = -1;
		while (i != str.length())
		{
			if ((i == 0 && str[i] != ' ') || (i != 0 && str[i - 1] == ' '&&str[i] != ' '))
			{
				if (end == -1)
					counts.push(i);
				else
					counts.push(i - end - 1);
				begin = i;
			}
			if ((str[i] != ' '&&i == str.length() - 1) || (i != str.length() - 1 && str[i] != ' '&&str[i + 1] == ' '))
			{
				end = i;
				list.push(str.substr(begin, end - begin + 1));
			}
			if (i == str.length() - 1 && str[i] == ' ')
			{
				if (end == -1)
					counts.push(i+1);
				else
					counts.push(i - end);
			}
			else if (str[i] != ' '&&i == str.length() - 1)
			{
				counts.push(0);
			}
			i++;
		}
		string new_str = "";
		int count = counts.top();
		counts.pop();
		for (int i = 0; i<count; i++)
			new_str.push_back(' ');
		
		while (list.size())
		{
			string cur_str = list.top();
			list.pop();
			new_str = new_str + cur_str;
			count = counts.top();
			counts.pop();
			for (int i = 0; i<count; i++)
				new_str.push_back(' ');
		}
		return new_str;
	}
};