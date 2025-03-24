/*除自身以外数组的乘积*/
//给你一个整数数组 nums，返回数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//题目数据 保证数组 nums之中任意元素的全部前缀元素和后缀的乘积都在32位整数范围内。
//请不要使用除法，且在 O(n) 时间复杂度内完成此题。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();// 假设数组为a b c d
        vector<int> prefix(n);// 前缀积 1   a   ab  abc
        vector<int> suffix(n);// 后缀积 bcd cd  d   1
        vector<int> answer(n);// 前缀积*后缀积
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