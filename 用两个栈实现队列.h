class Solution
{
public:
    void push(int node) {
		stack1.push(node);
    }
    int pop() {
		if(stack2.size())
		{
			int top=stack2.top();
			stack2.pop();
			return top;
		}
		else
		{
			while(stack1.size())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			int top=stack2.top();
			stack2.pop();
			return top;
		}
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};