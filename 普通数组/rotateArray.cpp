/*轮转数组*/
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
class Solution {
public:
    // 使用双端队列，空间复杂度较高
    /*void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; 
        for (int i = 0; i < n; i++) {
            dq.push_back(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        for (int i = 0; i < n; i++) {
            nums[i] = dq.front();
            dq.pop_front();
        }
    }*/
    // 数组翻转
    //该方法基于如下的事实：当我们将数组的元素向右移动 k 次后，尾部 kmodn 个元素会移动至数组头部，其余元素向后移动 kmodn 个位置。
    //该方法为数组的翻转：我们可以先将所有元素翻转，这样尾部的 kmodn 个元素就被移至数组头部，然后我们再翻转[0, kmodn−1] 区间的元素和[kmodn, n−1] 区间的元素即能得到最后的答案。
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
