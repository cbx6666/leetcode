/*完全平方数*/
//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
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