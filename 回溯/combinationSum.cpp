/*组合总和*/
//给你一个无重复元素的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按任意顺序返回这些组合。
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
class Solution {
public:
    vector<vector<int>> answer;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 对候选数组进行排序，便于后续剪枝操作
        sort(candidates.begin(), candidates.end());
        vector<int> sub;

        int n = candidates.size();
        // 遍历每个元素作为起始点，生成所有可能的组合
        for (int i = 0; i < n; i++) { 
            backTrace(candidates, sub, target, i);
        }

        return answer;
    }

    void backTrace(vector<int>& nums, vector<int>& sub, int target, int start) {
        int n = nums.size();
        // 剪枝：当前元素已大于剩余目标值，无法形成有效组合，直接返回
        if (nums[start] > target) {
            return;
        }
        // 找到一个有效组合：当前元素正好等于剩余目标值
        if (nums[start] == target) {
            sub.push_back(nums[start]);
            answer.push_back(sub);
            sub.pop_back();
            return;
        }

        // 选择当前元素，将其加入临时组合
        sub.push_back(nums[start]);
        // 递归尝试从当前索引开始的所有元素（允许重复使用）
        for (int i = start; i < n; i++) {
            backTrace(nums, sub, target - nums[start], i);
        }
        sub.pop_back();
    }
};