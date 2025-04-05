/*在排序数组中查找元素的第一个和最后一个元素*/
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回[-1, -1]。
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { // 先用二分查找找到该元素，再从该元素分别先前、先后二分查找
        int n = nums.size();
        int find = search(nums, 0, n - 1, target);
        if (find == -1) {
            return { -1, -1 };
        }
        int begin = find, end = find;
        for (int temp = begin; temp != -1;) { // 从目标元素的前一个元素开始先前二分查找，如果找不到目标元素即停止，确定第一个元素
            begin = temp;
            temp = search(nums, 0, temp - 1, target);
        }
        for (int temp = end; temp != -1;) { // 从目标元素的后一个元素开始先后二分查找，如果找不到目标元素即停止，确定最后一个元素
            end = temp;
            temp = search(nums, temp + 1, n - 1, target);
        }

        return { begin, end };
    }

    int search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) {
            return -1;
        }
        int middle = begin + (end - begin) / 2;
        int val = nums[middle];
        if (target > val) {
            return search(nums, middle + 1, end, target);
        }
        else if (target < val) {
            return search(nums, begin, middle - 1, target);
        }
        else {
            return middle;
        }
    }
};