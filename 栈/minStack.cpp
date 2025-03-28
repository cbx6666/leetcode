/*最小栈*/
//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
class MinStack {
public:
    stack<int> st;
    stack<int> min;

    MinStack() { min.push(INT_MAX); }

    void push(int val) {
        st.push(val);
        if (val < min.top()) {
            min.push(val);
        }
        else {
            min.push(min.top());
        }
    }

    void pop() {
        st.pop();
        min.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min.top(); }
};