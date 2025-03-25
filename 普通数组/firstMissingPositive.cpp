/*ȱʧ�ĵ�һ������*/
//����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
//����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
class Solution {
public:
    // ʵ���ϣ�����һ������Ϊ N �����飬����û�г��ֵ���С������ֻ����[1, N + 1] �С�������Ϊ���[1, N] �������ˣ���ô���� N + 1���������[1, N] ��û�г��ֵ���С��������
    // ��һ�ַ������û�����[1,N]�г��ֵ�����i�����������±�[i-1]��
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }

    // �ڶ��ַ�������ϣ��
    // ���ǽ�����������С�ڵ��� 0 �����޸�Ϊ N+1��
    // ��<= N��Ԫ��ȡ�෴��
    /*int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < n + 1 && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }*/
};