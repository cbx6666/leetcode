/*分割回文串*/
//给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
class Solution {
public:
    vector<vector<string>> answer;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        preprocessPalindrome(s); // 预处理所有可能的回文子串
        vector<string> sub;
        backTrace(s, 0, sub);
        return answer;
    }

    // 回溯函数：搜索所有以start为起点的有效分割方案
    void backTrace(const string& s, int start, vector<string>& sub) {
        // 终止条件：已处理完整个字符串，将当前分割方案加入结果集
        if (start == s.size()) {
            answer.push_back(sub);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) { // 如果s[start...i]是回文
                sub.push_back(s.substr(start, i - start + 1));
                backTrace(s, i + 1, sub);
                sub.pop_back();
            }
        }
    }

    // 动态规划法判断回文串
    void preprocessPalindrome(const string& s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));
        // 从后向前填充dp表（i从n-1到0，j从i到n-1）
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                // 状态转移方程：
                // 1. 首尾字符必须相等
                // 2. 且（子串长度<=2 或 内部子串s[i+1...j-1]是回文）
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
    }
};