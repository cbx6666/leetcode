/*����������*/
//����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0]; // ������������ʾ�Ե�ǰԪ�ؽ�β������������
        int maxValue = dp; // ȫ�����ֵ

        for (int i = 1; i < n; i++) {
            dp = max(nums[i], nums[i] + dp); // ���� dp
            maxValue = max(maxValue, dp);   // ����ȫ�����ֵ
        }

        return maxValue;
    }
};
