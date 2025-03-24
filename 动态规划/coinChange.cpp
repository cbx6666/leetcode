/*零钱兑换*/
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 - 1 。
//你可以认为每种硬币的数量是无限的。
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            int min = dp[i];
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    min = min < dp[i - coins[j]] ? min : dp[i - coins[j]];
                }
            }
            if (min < INT_MAX) {
                dp[i] = min + 1;
            }
        }
        
        return dp[amount] < INT_MAX ? dp[amount] : -1;
    }
};
