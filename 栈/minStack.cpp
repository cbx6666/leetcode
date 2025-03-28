/*��Сջ*/
//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
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