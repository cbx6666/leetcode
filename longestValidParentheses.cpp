/*最长有效括号*/
//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
class Solution {
public:
    // 自己用栈做的方法
    /* int longestValidParentheses(string s) {
        int n = s.size();
        vector<bool> valid(n, false);
        stack<int> st;
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty() && s[st.top()] == '(') {
                    valid[st.top()] = true;
                    st.pop();
                    valid[i] = true;
                } else {
                    st.push(i);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                count++;
                maxLength = max(maxLength, count);
            } else {
                count = 0;
            }
        }

        return maxLength;
    }*/

    // 动态规划法
    int longestValidParentheses(string s) {
        int maxAns = 0, n = s.length();
        vector<int> dp(n, 0);

        // 以 ‘(’ 结尾的子串对应的 dp 值必定为 0 ，我们只需要求解 ‘)’ 在 dp 数组中对应位置的值
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (s[i-1] == ')') {
                    // 如果倒数第二个 ‘)’ 是一个有效子字符串的一部，对于最后一个 ‘)’ ，如果它是一个更长子字符串的一部分，
                    // 那么它一定有一个对应的 ‘(’ ，且它的位置在倒数第二个 ‘)’ 所在的有效子字符串的前面
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') { // 如果dp[i - 1] == 0,s[i - 1] == ')',自然不满足
                        dp[i] = (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                    }
                }
            }
            maxAns = max(maxAns, dp[i]);
        }

        return maxAns;
    }
};