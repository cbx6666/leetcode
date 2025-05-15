/*�ָ���Ĵ�*/
//����һ���ַ��� s�����㽫 s �ָ��һЩ �Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
class Solution {
public:
    vector<vector<string>> answer;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        preprocessPalindrome(s); // Ԥ�������п��ܵĻ����Ӵ�
        vector<string> sub;
        backTrace(s, 0, sub);
        return answer;
    }

    // ���ݺ���������������startΪ������Ч�ָ��
    void backTrace(const string& s, int start, vector<string>& sub) {
        // ��ֹ�������Ѵ����������ַ���������ǰ�ָ����������
        if (start == s.size()) {
            answer.push_back(sub);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) { // ���s[start...i]�ǻ���
                sub.push_back(s.substr(start, i - start + 1));
                backTrace(s, i + 1, sub);
                sub.pop_back();
            }
        }
    }

    // ��̬�滮���жϻ��Ĵ�
    void preprocessPalindrome(const string& s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));
        // �Ӻ���ǰ���dp��i��n-1��0��j��i��n-1��
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                // ״̬ת�Ʒ��̣�
                // 1. ��β�ַ��������
                // 2. �ң��Ӵ�����<=2 �� �ڲ��Ӵ�s[i+1...j-1]�ǻ��ģ�
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
    }
};