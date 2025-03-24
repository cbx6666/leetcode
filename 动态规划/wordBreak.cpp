/*单词拆分*/
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_set<string> uset;
        for (int i = 0; i < n; i++) {
            uset.insert(wordDict[i]);
        }
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && uset.count(s.substr(j, i - j))) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};