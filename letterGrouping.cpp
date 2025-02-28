/*字母异位词分组*/
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            umap[str].push_back(strs[i]);
        }
        for (const auto& pair : umap) {
            answer.push_back(pair.second);
        }
        return answer;
    }
};