/*����ˮ*/
//���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
class Solution {
public:
    // ʱ�临�Ӷ�ΪO(n2),�޷�ͨ������
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

    // ʹ��˫ָ�뷨
    /*int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        int left = 0, right = n - 1;                          // ˫ָ��
        int leftMax = height[left], rightMax = height[right]; // �������ֵ
        int volume = 0;

        while (left < right) {
            // �����������ֵ
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // ��С��һ�������ˮ��
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

    // ʹ�õ���ջ�Ľⷨ
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) { // ����ջ����ջ�׵�ջ���ݼ���ֱ��height[i]����ջ��Ԫ�أ�height[i]��Ϊ�ұ߽�
                int top = stk.top(); // ��¼��͵�
                stk.pop(); // ����ջ��Ԫ��
                
                if (stk.empty()) {
                    break;
                }

                int left = stk.top(); // ȡ������͵����ջ��Ԫ����Ϊ�ұ߽�

                // ������ˮ��
                int currentWidth = i - left - 1;
                int currentHeight = min(height[left], height[i]) - height[top];
                ans += currentHeight * currentWidth;
            }
            stk.push(i);
        }
        return ans;
    }
};