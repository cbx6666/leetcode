/*�˻����������*/
//����һ���������� nums �������ҳ������г˻����ķǿ����� �����飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDp(nums);
        vector<int> minDp(nums);
        int maxValue = *max_element(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                maxDp[i] = max(maxDp[i - 1] * nums[i], maxDp[i]);
                minDp[i] = min(minDp[i - 1] * nums[i], minDp[i]);
            }
            else {
                minDp[i] = min(maxDp[i - 1] * nums[i], minDp[i]);
                maxDp[i] = max(minDp[i - 1] * nums[i], maxDp[i]);
            }
            maxValue = max(maxValue, maxDp[i]);
        }
        return maxValue;
    }
};