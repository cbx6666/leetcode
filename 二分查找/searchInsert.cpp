/*搜索插入位置*/
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return partition(nums, 0, nums.size() - 1, target);
    }

    int partition(vector<int>& nums,int start,int end,int target) {
        int n = nums.size();
        int middle = (start + end) / 2;

        if (start > end) { // 在二分查找中，当 start > end 时，表示搜索区间已经无效（区间为空），此时可以确定 target 不存在于数组中。
            return start; // 但此时 start 的值隐式地指向了 target 应该插入的位置，使得插入后数组仍然有序(可以数学证明)。
        }

        if (target > nums[middle]) {
            return partition(nums, middle + 1, end, target);
        }
        else if (target < nums[middle]) {
            return partition(nums, start, middle - 1, target);
        }
        else {
            return middle;
        }
    }
};