/*搜索旋转排序数组*/
//整数数组 nums 按升序排列，数组中的值 互不相同 。
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。
// 例如，[0, 1, 2, 4, 5, 6, 7] 在下标 3 处经旋转后可能变为[4, 5, 6, 7, 0, 1, 2] 。
//给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 - 1 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
class Solution { // 找到中间值后，一半部分是有序的，另一半部分是乱序的
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) { // 通解，既可以处理递增数组的二分搜索，又可以处理旋转数组
            int mid = left + (right - left) / 2; 

            // 直接找到目标值
            if (nums[mid] == target) {
                return mid;
            }

            // 判断左半部分是否有序
            if (nums[left] <= nums[mid]) {
                // 如果目标值在有序的左半部分范围内
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // 在左半部分继续搜索（正常的二分搜索）
                }
                else {
                    left = mid + 1;  // 否则去右半部分搜索
                }
            }
            // 右半部分有序
            else {
                // 如果目标值在有序的右半部分范围内
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // 在右半部分继续搜索（正常的二分搜索）
                }
                else {
                    right = mid - 1; // 否则去左半部分搜索
                }
            }
        }

        // 未找到目标值
        return -1;
    }
};