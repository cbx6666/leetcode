/*最长连续序列*/
//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 将所有数字存入哈希集合
        unordered_set<int> rank(nums.begin(), nums.end());
        int longest = 0;

        // 遍历哈希集合
        for (int num : rank) {
            // 如果当前数字是连续序列的起点
            if (rank.find(num - 1) == rank.end()) {
                int currentNum = num;
                int currentLength = 1;

                // 扩展连续序列
                while (rank.find(currentNum + 1) != rank.end()) {
                    currentNum++;
                    currentLength++;
                }

                // 更新最长序列长度
                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};
