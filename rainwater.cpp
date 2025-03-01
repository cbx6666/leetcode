/*接雨水*/
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
class Solution {
public:
    // 时间复杂度为O(n2),无法通过测试
    /*int trap(vector<int>& height) {
        int maxHeight = 0, n = height.size();
        int volume = 0;
        for (int i = 0; i < n; i++) {
            maxHeight = maxHeight > height[i] ? maxHeight : height[i];
        }
        for (int level = 1; level <= maxHeight; level++) {
            int left = 0, right = 0;
            for (int i = 0; i < n; i++) {
                if (height[i] >= level) {
                    left = i, right = i;
                    break;
                }
            }
            while (right < n - 1) {
                right++;
                if (height[right] >= level) {
                    volume += (right - left - 1);
                    left = right;
                }
            }
        }
        return volume;
    }*/

    // 使用双指针法
    /*int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        int left = 0, right = n - 1;                          // 双指针
        int leftMax = height[left], rightMax = height[right]; // 左右最大值
        int volume = 0;

        while (left < right) {
            // 更新左右最大值
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // 较小的一侧决定雨水量
            if (leftMax < rightMax) {
                volume += leftMax - height[left];
                left++;
            } else {
                volume += rightMax - height[right];
                right--;
            }
        }

        return volume;
    }*/

    // 使用单调栈的解法
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) { // 单调栈，从栈底到栈顶递减，直到height[i]高于栈顶元素，height[i]作为右边界
                int top = stk.top(); // 记录最低点
                stk.pop(); // 弹出栈顶元素
                
                if (stk.empty()) {
                    break;
                }

                int left = stk.top(); // 取高于最低点的新栈顶元素作为右边界

                // 计算雨水量
                int currentWidth = i - left - 1;
                int currentHeight = min(height[left], height[i]) - height[top];
                ans += currentHeight * currentWidth;
            }
            stk.push(i);
        }
        return ans;
    }
};