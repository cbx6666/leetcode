/*乘积最大子数组*/
//给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
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