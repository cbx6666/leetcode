/*子集*/
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
class Solution {
public:
    vector<vector<int>> answer;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> nullSub;
        int n = nums.size();
        // 遍历所有可能的子集大小（从0到n）
        for (int i = 0; i <= n; i++) {
            selectN(nums, nullSub, i, 0);
        }

        return answer;
    }

    void selectN(vector<int>& nums, vector<int>& sub, int amount, int start) {
        int n = nums.size();
        // 终止条件1：已经选够 `amount` 个元素，将当前子集加入答案
        if (amount == 0) {
            answer.push_back(sub);
        }
        // 终止条件2：剩余可选的元素不足以凑够 `amount` 个，直接返回
        if (start + amount > n) {
            return;
        }

        // 从 `start` 开始遍历可选元素
        for (int i = start; i < n; i++) {
            sub.push_back(nums[i]);
            selectN(nums, sub, amount - 1, i + 1); // 递归选择下一个元素（避免重复）
            sub.pop_back();
        }
    }
};