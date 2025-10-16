/*寻找两个正序数组中的中位数*/
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log(m + n)) 。
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 != 0) {
            // 奇数情况：直接返回中间值
            return getKthElement(nums1, nums2, (m + n) / 2 + 1);
        }
        else {
            // 偶数情况：返回中间两个数的平均值
            return (getKthElement(nums1, nums2, (m + n) / 2) + getKthElement(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }

    // 二分法求第k小元素（核心算法）
    double getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int offset1 = 0, offset2 = 0; // 当前数组的有效起始偏移量
        while (true) {
            // 边界情况处理
            if (offset1 == m) { // nums1已全部排除
                return nums2[offset2 + k - 1];
            }
            if (offset2 == n) { // nums2已全部排除
                return nums1[offset1 + k - 1];
            }
            if (k == 1) { // 找第1小的元素时直接比较当前头部
                return min(nums1[offset1], nums2[offset2]);
            }

            /* 二分核心逻辑 */
            // 计算比较步长（取k/2与剩余长度的较小值）
            int p1 = min(k / 2, m - offset1); // nums1的探测长度
            int p2 = min(k / 2, n - offset2); // nums2的探测长度
            int index1 = offset1 + p1 - 1; // nums1的比较位置
            int index2 = offset2 + p2 - 1; // nums2的比较位置
            // 排除不可能包含第k元素的区间
            if (nums1[index1] <= nums2[index2]) {
                offset1 += p1;  // 排除nums1的前p1个元素
                k -= p1; // 更新剩余需要找的元素序号
            }
            else {
                offset2 += p2; // 排除nums2的前p2个元素
                k -= p2;
            }
        }
    }
};