/*���ʲ��*/
//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣������������ֵ��г��ֵ�һ����������ƴ�ӳ� s �򷵻� true��
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