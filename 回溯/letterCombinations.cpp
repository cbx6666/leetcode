/*�绰�������ĸ���*/
//����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
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