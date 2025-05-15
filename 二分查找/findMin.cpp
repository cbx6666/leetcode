/*寻找旋转排序数组中的最小值*/
//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
//例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
//若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 2]
//若旋转 7 次，则可以得到[0, 1, 2, 4, 5, 6, 7]
//给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int begin = 0, end = n - 1, min = 0;
        while (begin <= end) {
            int middle = begin + (end - begin) / 2;
            // 数组有序，则取begin作为最小值
            if (nums[middle] >= nums[begin] && nums[middle] <= nums[end]) {
                min = begin;
                break;
            }
            // 数组无序，且end - begin <= 1，则取end作为最小值
            if (end - begin <= 1) {
                min = end;
                break;
            }
            if (nums[middle] > nums[end]) {
                begin = middle;
            }
            if (nums[middle] < nums[begin]) {
                end = middle;
            }
        }

        return nums[min];
    }
};