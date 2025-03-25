/*缺失的第一个正数*/
//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
//请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
class Solution {
public:
    // 实际上，对于一个长度为 N 的数组，其中没有出现的最小正整数只能在[1, N + 1] 中。这是因为如果[1, N] 都出现了，那么答案是 N + 1，否则答案是[1, N] 中没有出现的最小正整数。
    // 第一种方法，置换，将[1,N]中出现的数字i，放在数组下标[i-1]处
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }

    // 第二种方法，哈希表
    // 我们将数组中所有小于等于 0 的数修改为 N+1；
    // 将<= N的元素取相反数
    /*int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) < n + 1 && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }*/
};