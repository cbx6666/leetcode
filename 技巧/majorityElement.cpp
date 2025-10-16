/*多数元素*/
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数大于 ⌊n/2⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == max) {
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                max = nums[i];
                count = 1;
            }
        }
        return max;
    }
};