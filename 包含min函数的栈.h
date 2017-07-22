class Solution {
public:
    stack<int> st, minSt;//st表示存储元素的栈，minSt保存每次栈操作时，保存栈中最小元素
    void push(int value) {
        st.push(value);
        if (minSt.empty()){//如果栈minSt为空，将value入栈，value就是当前最小的元素
            minSt.push(value);
        }
        else {//如果栈minSt不为空，将value的值与minStrel栈的栈顶元素比较。因为minSt栈的栈顶元素此时为栈中所有元素的最小值
            if (value < minSt.top())
			{
                minSt.push(value);
            }
            else 
			{
                minSt.push(minSt.top());
            }
        }
        return;
    }
    void pop() {//出栈时，需要对两个栈st和minSt同时操作
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
        return;
    }
    int top() {
        if (!st.empty()){
            return st.top();
        }
        return 0;
    }
    int min() {
        if (!minSt.empty()) {
            return minSt.top();
        }
        return 0;
    }
};