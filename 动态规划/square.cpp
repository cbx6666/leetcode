/*��ȫƽ����*/
//����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minDp = dp[i];
            for (int j = 1; j * j <= i; j++) {
                minDp = minDp < dp[i - j * j] ? minDp : dp[i - j * j];
            }
            dp[i] = minDp + 1;
        }
        return dp[n];
    }
};