/*跳跃游戏*/
//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//0 <= j <= nums[i]
//i + j < n
//返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int i = 0;
        while (i < n - 1) {
            int maxStep = i;
            int nextStep = 0;
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (i + j + nums[i + j] > maxStep) {
                    maxStep = i + j + nums[i + j];
                    nextStep = i + j;
                }
                if (i + j == n - 1) {
                    nextStep = i + j;
                }
            }
            i = nextStep;
            step++;

            if (nextStep >= n - 1) {
                break;
            }
        }
        return step;
    }
};