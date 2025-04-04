/*好子数组的最大分数*/
//给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。
//一个子数组(i, j) 的 分数 定义为 min(nums[i], nums[i + 1], ..., nums[j])* (j - i + 1) 。一个 好子数组的两个端点下标需要满足 i <= k <= j 。
//请你返回好子数组的最大可能分数 。
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) { // 双指针法
        int n = nums.size();
        int leftMin = nums[k], rightMin = nums[k];
        for (int i = k; i >= 0; i--) { // 从k向左记录最小值
            if (nums[i] < leftMin) {
                leftMin = nums[i];
            }
            nums[i] = leftMin;
        }
        for (int i = k; i < n; i++) { // 从k向右记录最小值
            if (nums[i] < rightMin) {
                rightMin = nums[i];
            }
            nums[i] = rightMin;
        }

        int left = 0, right = n - 1, maxVal = INT_MIN; 
        while (left <= right) {
            int val = (right - left + 1) * min(nums[left], nums[right]); // 与盛水最多的容器原理相同
            maxVal = max(val, maxVal);
            if (left == k && right == k) {
                break;
            }
            else if (left == k) {
                --right;
            }
            else if (right == k) {
                ++left;
            }
            else if (nums[left] < nums[right]) {
                ++left;
            }
            else {
                --right;
            }
        }

        return maxVal;
    }

    // 另一种方法
    // 做法与柱状图中的最大矩形完全相同，只需要添加一个判断条件
    /*for (int i = 0; i < n; i++) {
        if (left[i] < k && right[i] > k) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
    }*/
};