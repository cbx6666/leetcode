/*编辑距离*/
// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
class Solution {
    public:
        int minDistance(string word1, string word2) {
            // 编辑距离的关键性质是：存在一个最优操作序列，其中所有操作都发生在字符串末尾。
            // 这不是因为实际编辑时只能操作末尾，而是因为任何中间操作都可以等价地"延迟"到末尾处理，而不增加操作次数。
            int m = word1.size();
            int n = word2.size();
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (int i = 0; i <= m; i++) {
                dp[i][0] = i;
            }
            for (int i = 0; i <= n; i++) {
                dp[0][i] = i;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                }
            }
    
            return dp[m][n];
        }
    };