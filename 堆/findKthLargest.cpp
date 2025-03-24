/*数组中第K个最大元素*/
//返回数组中第K大的元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // 将问题转换为寻找第(n-k)小的元素（因为第k大等于第n-k+1小）
        return quickSelect(nums, 0, n - 1, n - k);
    }

    // 快速选择算法实现
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        // 递归终止条件：当区间只有一个元素时，直接返回该元素
        if (left == right) {
            return nums[left];
        }

        int pivotIndex = partition(nums, left, right);  // 对数组进行分区，并返回基准元素的最终位置

        // 判断基准元素的位置与k的关系
        if (pivotIndex == k) {
            return nums[pivotIndex];
        }
        else if (pivotIndex < k) {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
        else {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }

    }

    // 分区函数：将数组分为小于基准元素和大于等于基准元素的两部分,返回基准元素的索引
    // 单路分区，速度较慢
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        // 获取基准元素的值
        int pivotValue = nums[pivotIndex];

        // 将基准元素交换到数组的最右边，方便后续操作
        swap(nums[pivotIndex], nums[right]);

        // storeIndex用于标记小于基准元素的区域的右边界，可以保证该索引左侧的元素都小于基准元素
        int storeIndex = left;

        for (int i = left; i < right; i++) {
            if (nums[i] < pivotValue) {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }

        // 此时，storeIndex左边都是小于基准元素的，右边都是大于等于基准元素的
        swap(nums[right], nums[storeIndex]);

        return storeIndex;
    }

    // 双路区分
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int leftPtr = left + 1;
        int rightPtr = right;

        while (leftPtr <= rightPtr) {
            while (leftPtr <= right && nums[leftPtr] < pivot) {
                leftPtr++;
            }
            while (rightPtr >= left && nums[rightPtr] > pivot) {
                rightPtr--;
            }
            if (leftPtr <= rightPtr) {
                swap(nums[leftPtr], nums[rightPtr]);
                leftPtr++;
                rightPtr--;
            }
        }

        swap(nums[left], nums[rightPtr]);
        return rightPtr;
    }
};
