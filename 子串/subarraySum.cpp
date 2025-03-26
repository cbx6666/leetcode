/*和为K的子数组*/
//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // 计算前缀和，对于i > j，如果i的前缀和减j的前缀和等于k，则说明数组j + 1 ~ i的和为k。
        unordered_map<int, int> mp; // 记录每个前缀和及其个数
        mp[0] = 1; // 处理前缀和正好为k
        int count = 0, pre = 0;
        for (int num : nums) {
            pre += num; // 计算前缀和
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }

        return count;
    }
};