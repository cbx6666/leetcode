/*���������������*/
//����һ���������� nums ���±�� 0 ��ʼ����һ������ k ��
//һ��������(i, j) �� ���� ����Ϊ min(nums[i], nums[i + 1], ..., nums[j])* (j - i + 1) ��һ�� ��������������˵��±���Ҫ���� i <= k <= j ��
//���㷵�غ�������������ܷ��� ��
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) { // ˫ָ�뷨
        int n = nums.size();
        int leftMin = nums[k], rightMin = nums[k];
        for (int i = k; i >= 0; i--) { // ��k�����¼��Сֵ
            if (nums[i] < leftMin) {
                leftMin = nums[i];
            }
            nums[i] = leftMin;
        }
        for (int i = k; i < n; i++) { // ��k���Ҽ�¼��Сֵ
            if (nums[i] < rightMin) {
                rightMin = nums[i];
            }
            nums[i] = rightMin;
        }

        int left = 0, right = n - 1, maxVal = INT_MIN; 
        while (left <= right) {
            int val = (right - left + 1) * min(nums[left], nums[right]); // ��ʢˮ��������ԭ����ͬ
            maxVal = max(val, maxVal);
            if (left == k && right == k) {
                break;
            }
            else if (left == k) {
                --right;
            }
            else if (right == k) {
                ++left;
            }
            else if (nums[left] < nums[right]) {
                ++left;
            }
            else {
                --right;
            }
        }

        return maxVal;
    }

    // ��һ�ַ���
    // ��������״ͼ�е���������ȫ��ͬ��ֻ��Ҫ���һ���ж�����
    /*for (int i = 0; i < n; i++) {
        if (left[i] < k && right[i] > k) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
    }*/
};