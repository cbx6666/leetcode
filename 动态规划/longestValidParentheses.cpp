/*���Ч����*/
//����һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
class Solution {
public:
    // �Լ���ջ���ķ���
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

    // ��̬�滮��
    int longestValidParentheses(string s) {
        int maxAns = 0, n = s.length();
        vector<int> dp(n, 0);

        // �� ��(�� ��β���Ӵ���Ӧ�� dp ֵ�ض�Ϊ 0 ������ֻ��Ҫ��� ��)�� �� dp �����ж�Ӧλ�õ�ֵ
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (s[i-1] == ')') {
                    // ��������ڶ��� ��)�� ��һ����Ч���ַ�����һ�����������һ�� ��)�� ���������һ���������ַ�����һ���֣�
                    // ��ô��һ����һ����Ӧ�� ��(�� ��������λ���ڵ����ڶ��� ��)�� ���ڵ���Ч���ַ�����ǰ��
                    if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') { // ���dp[i - 1] == 0,s[i - 1] == ')',��Ȼ������
                        dp[i] = (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                    }
                }
            }
            maxAns = max(maxAns, dp[i]);
        }

        return maxAns;
    }
};