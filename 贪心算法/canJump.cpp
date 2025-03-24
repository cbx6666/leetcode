/*跳跃游戏*/
//给你一个非负整数数组 nums ，你最初位于数组的第一个下标。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;  // 当前能够到达的最远位置

        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                // 如果当前位置已经超过了能够到达的最远位置，说明无法到达
                return false;
            }
            // 更新能够到达的最远位置
            maxReach = max(maxReach, i + nums[i]);

            // 如果能够到达最后一个位置，返回 true
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return false;
    }
};
