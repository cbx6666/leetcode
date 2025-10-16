/*最小路径和*/
// 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 每次只能向下或者向右移动一步。
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(n, 0);
        vector<int> dp(n, 0);
        dp[n - 1] = grid[m - 1][n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = grid[m - 1][i] + dp[i + 1];
        }
        pre = dp;
        for (int i = m - 2; i >= 0; i--) {
            dp[n - 1] = grid[i][n - 1] + pre[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                dp[j] = grid[i][j] + min(pre[j], dp[j + 1]);
            }
            pre = dp;
        }
        
        return dp[0];
    }
};