/*ÿ���¶�*/
//����һ���������� temperatures ����ʾÿ����¶ȣ�����һ������ answer ������ answer[i] ��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ���������������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { // ����������飬���쵥��ջ��ջ��Ԫ�ؼ�Ϊ��һ�θ����¶�
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) { // ���쵥��ջ
                st.pop();
            }
            if (st.empty()) {
                answer[i] = 0; // ���²���������
            }
            else {
                answer[i] = st.top() - i;
            }
            st.push(i);
        }

        return answer;
    }
};