/*��״ͼ�е�������*/
//���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
//���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // ����ÿ�����ӣ��ֱ��������Ѱ�Ҹ߶ȵ������������
        int n = heights.size();
        stack<int> leftStack, rightStack; // ����ջ����ջ����ջ�׵ݼ�
        vector<int> left(n), right(n); // ����ÿ�����ӣ���/�Ҳ��������ı����������ӵ�λ��

        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() &&
                heights[leftStack.top()] >= heights[i]) { // ����������ߵ�����
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