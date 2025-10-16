/*电话号码的字母组合*/
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
class Solution {
public:
    vector<string> answer;

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> ump = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

        string sub;
        backTrace(digits, sub, ump, 0);

        return answer;
    }

    void backTrace(string& digits, string& sub, unordered_map<char, string>& ump, int position) {
        int n = ump[digits[position]].size();
        for (int i = 0; i < n; i++) {
            char c = ump[digits[position]][i];
            sub.push_back(c);
            if (sub.size() == digits.size()) {
                answer.push_back(sub);
            }
            else {
                backTrace(digits, sub, ump, position + 1);
            }
            sub.pop_back();
        }
    }
};