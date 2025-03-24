/*��������������ĳ˻�*/
//����һ���������� nums���������� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��
//��Ŀ���� ��֤���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����32λ������Χ�ڡ�
//�벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();// ��������Ϊa b c d
        vector<int> prefix(n);// ǰ׺�� 1   a   ab  abc
        vector<int> suffix(n);// ��׺�� bcd cd  d   1
        vector<int> answer(n);// ǰ׺��*��׺��
        prefix[0] = 1, suffix[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - i - 1] = suffix[n - i] * nums[n - i];
        }
        for (int i = 0; i < n; i++) {
            answer[i] = prefix[i] * suffix[i];
        }
        return answer;
    }
};