/*最大子数组和*/
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0]; // 滚动变量，表示以当前元素结尾的最大子数组和
        int maxValue = dp; // 全局最大值

        for (int i = 1; i < n; i++) {
            dp = max(nums[i], nums[i] + dp); // 更新 dp
            maxValue = max(maxValue, dp);   // 更新全局最大值
        }

        return maxValue;
    }
};
