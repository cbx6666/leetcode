/*括号生成*/
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
class Solution {
public:
    vector<string> answer;
    int left_num = 0;
    int right_num = 0;

    vector<string> generateParenthesis(int n) {
        string sub;
        backTrace(n, sub);
        return answer;
    }

    void backTrace(int n, string sub) {
        // 终止条件：当字符串长度等于 2n 时，说明已生成一个有效组合
        if (sub.size() == 2 * n) {
            answer.push_back(sub);
            return;
        }
        // 选择添加左括号的条件：左括号数量未达到 n
        if (left_num < n) {
            sub.push_back('(');
            left_num++;
            backTrace(n, sub);
            sub.pop_back();
            left_num--;
        }
        // 选择添加右括号的条件：右括号数量小于左括号数量（保证有效性）
        if (right_num < left_num) {
            sub.push_back(')');
            right_num++;
            backTrace(n, sub);
            sub.pop_back();
            right_num--;
        }
    }
};