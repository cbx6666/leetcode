/*搜索二维数组*/
//给你一个满足下述两条属性的 m x n 整数矩阵：
//每行中的整数从左到右按非严格递增顺序排列。
//每行的第一个整数大于前一行的最后一个整数。
//给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        vector<int> rowFirstVal(n);
        for (int i = 0; i < n; i++) {
            rowFirstVal[i] = matrix[i][0];
        }
        int row = confirmRow(rowFirstVal, 0, n - 1, target);
        if (row < 0) {
            return false;
        }

        return search(matrix[row], 0, matrix[row].size() - 1, target);
    }

    int confirmRow(vector<int>& nums, int begin, int end, int target) { // 用二分查找确定行
        if (begin > end) {
            return -1;
        }
        if (begin == end) {
            return begin;
        }

        int middle = (begin + end) / 2;
        if (nums[middle] <= target) {
            if (middle == nums.size() - 1 || nums[middle + 1] > target) {
                return middle;
            }
            else {
                return confirmRow(nums, middle + 1, end, target);
            }
        }
        else {
            return confirmRow(nums, begin, middle - 1, target);
        }
    }

    bool search(vector<int>& nums, int begin, int end, int target) { // 在一行中二分查找
        if (begin > end) {
            return false;
        }
        int middle = (begin + end) / 2;

        if (target > nums[middle]) {
            return search(nums, middle + 1, end, target);
        }
        else if (target < nums[middle]) {
            return search(nums, begin, middle - 1, target);
        }
        else {
            return true;
        }
    }
};