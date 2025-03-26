/*滑动窗口最大值*/
//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回滑动窗口中的最大值 。
// 对于i < j，若nums[i] < nums[j]，由于 nums[j] 的存在，nums[i] 一定不会是滑动窗口中的最大值了，我们可以将 nums[i] 永久地移除。
// 因此我们可以使用一个队列存储所有还没有被移除的下标。
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { // 采用单调队列，队列的值递减，保证头部值最大
        int n = nums.size();
        deque<int> dq;
        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (i < k - 1) {
                while (!dq.empty() && dq.back() < nums[i]) { // 维护队列的单调性
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
            else {
                while (!dq.empty() && dq.back() < nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(nums[i]);

                answer.push_back(dq.front()); // 获取当前滑动窗口的最大值

                if (dq.front() == nums[i - k + 1]) { // 如果左窗口数字仍然存在，则必在队列头部，删除最左端数字
                    dq.pop_front();
                }
            }
        }

        return answer;
    }
};