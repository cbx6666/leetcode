/*寻找重复数*/
// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 额外空间。
class Solution {
// 将数组转换为链表，用重复数则代表有环，用快慢指针找到环的入口即为重复数
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};