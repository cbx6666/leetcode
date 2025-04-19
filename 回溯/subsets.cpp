/*�Ӽ�*/
//����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
class Solution {
public:
    vector<vector<int>> answer;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> nullSub;
        int n = nums.size();
        // �������п��ܵ��Ӽ���С����0��n��
        for (int i = 0; i <= n; i++) {
            selectN(nums, nullSub, i, 0);
        }

        return answer;
    }

    void selectN(vector<int>& nums, vector<int>& sub, int amount, int start) {
        int n = nums.size();
        // ��ֹ����1���Ѿ�ѡ�� `amount` ��Ԫ�أ�����ǰ�Ӽ������
        if (amount == 0) {
            answer.push_back(sub);
        }
        // ��ֹ����2��ʣ���ѡ��Ԫ�ز����Դչ� `amount` ����ֱ�ӷ���
        if (start + amount > n) {
            return;
        }

        // �� `start` ��ʼ������ѡԪ��
        for (int i = start; i < n; i++) {
            sub.push_back(nums[i]);
            selectN(nums, sub, amount - 1, i + 1); // �ݹ�ѡ����һ��Ԫ�أ������ظ���
            sub.pop_back();
        }
    }
};