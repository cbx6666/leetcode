/*移动零*/
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//示例 1:
//输入: nums = [0, 1, 0, 3, 12]
//输出 : [1, 3, 12, 0, 0]
//示例 2 :
//输入 : nums = [0]
//输出 : [0]
class Solution {
public:
    // 第一次提交，使用哈希表，复杂度很高...
    /*void moveZeroes(vector<int>& nums) {
        unordered_map<int, int> rank;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                rank[index] = nums[i];
                index++;
            }
        }
        int amountOfZero = nums.size() - index;
        
        for (int i = 0; i < index; i++) {
            nums[i] = rank[i];
        }
        for (int i = 0; i < amountOfZero; i++) {
            nums[i + index] = 0;
        }
    }*/

    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
