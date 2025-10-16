/*最长回文串*/
// 给你一个字符串 s，找到 s 中最长的 回文 子串。
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp;
        dp.resize(n, vector<bool>(n, false));
        int maxLength = 1;
        int start = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j || (j - i == 1 && s[i] == s[j])) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        start = i;
                    }
                }
                if (j - i > 1 && dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};