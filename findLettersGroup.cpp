/*找到字符串中所有字母异位词*/
//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        int n = s.size(), m = p.size();

        if (n < m) {
            return answer;  
        }

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            if (i > m - 1) { // 窗口长度达到p字符串长度
                sCount[s[i - m] - 'a']--; // 左边界右移
            }
            sCount[s[i] - 'a']++; // 右边界右移
            if (sCount == pCount) {
                answer.push_back(i - m + 1);
            }
        }

        return answer;
    }
};