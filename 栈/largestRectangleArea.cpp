/*柱状图中的最大矩形*/
//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // 对于每个柱子，分别向左和右寻找高度低于自身的柱子
        int n = heights.size();
        stack<int> leftStack, rightStack; // 单调栈，从栈顶到栈底递减
        vector<int> left(n), right(n); // 对于每个柱子，左/右侧距离最近的比自身矮的柱子的位置

        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() &&
                heights[leftStack.top()] >= heights[i]) { // 弹出比自身高的柱子
                leftStack.pop();
            }
            left[i] = leftStack.empty() ? -1 : leftStack.top();
            leftStack.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() &&
                heights[rightStack.top()] >= heights[i]) {
                rightStack.pop();
            }
            right[i] = rightStack.empty() ? n : rightStack.top();
            rightStack.push(i);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};