/*每日温度*/
//给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { // 逆序遍历数组，构造单调栈，栈顶元素即为下一次更高温度
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) { // 构造单调栈
                st.pop();
            }
            if (st.empty()) {
                answer[i] = 0; // 气温不会再升高
            }
            else {
                answer[i] = st.top() - i;
            }
            st.push(i);
        }

        return answer;
    }
};