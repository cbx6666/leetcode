/*划分字母区间*/
//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
//例如，字符串 "ababcc" 能够被分为["abab", "cc"]，但类似["aba", "bcc"] 或["ab", "ab", "cc"] 的划分是非法的。
//注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
//返回一个表示每个字符串片段的长度的列表。
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int sIndex = 0, groupIndex = 0;
        vector<int> answer;

        unordered_map<char, int> umap; // 记录每个字母最后一次出现的位置
        for (int i = 0; i < n; i++) {
            umap[s[i]] = i;
        }

        while (sIndex < n) {
            int end = sIndex;
            answer.push_back(0);
            while (sIndex <= end) {
                if (umap[s[sIndex]] != sIndex) { // 为了将同一字母放在同一片段中，找到该字母最后出现的位置，更新结尾
                    end = max(end, umap[s[sIndex]]);
                }
                answer[groupIndex]++;
                sIndex++;
            }
            groupIndex++;
        }
        return answer;
    }
};