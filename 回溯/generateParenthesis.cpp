/*��������*/
//���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
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
        // ��ֹ���������ַ������ȵ��� 2n ʱ��˵��������һ����Ч���
        if (sub.size() == 2 * n) {
            answer.push_back(sub);
            return;
        }
        // ѡ����������ŵ�����������������δ�ﵽ n
        if (left_num < n) {
            sub.push_back('(');
            left_num++;
            backTrace(n, sub);
            sub.pop_back();
            left_num--;
        }
        // ѡ����������ŵ�����������������С����������������֤��Ч�ԣ�
        if (right_num < left_num) {
            sub.push_back(')');
            right_num++;
            backTrace(n, sub);
            sub.pop_back();
            right_num--;
        }
    }
};