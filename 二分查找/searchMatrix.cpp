/*������ά����*/
//����һ�����������������Ե� m x n ��������
//ÿ���е����������Ұ����ϸ����˳�����С�
//ÿ�еĵ�һ����������ǰһ�е����һ��������
//����һ������ target ����� target �ھ����У����� true �����򣬷��� false ��
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        vector<int> rowFirstVal(n);
        for (int i = 0; i < n; i++) {
            rowFirstVal[i] = matrix[i][0];
        }
        int row = confirmRow(rowFirstVal, 0, n - 1, target);
        if (row < 0) {
            return false;
        }

        return search(matrix[row], 0, matrix[row].size() - 1, target);
    }

    int confirmRow(vector<int>& nums, int begin, int end, int target) { // �ö��ֲ���ȷ����
        if (begin > end) {
            return -1;
        }
        if (begin == end) {
            return begin;
        }

        int middle = (begin + end) / 2;
        if (nums[middle] <= target) {
            if (middle == nums.size() - 1 || nums[middle + 1] > target) {
                return middle;
            }
            else {
                return confirmRow(nums, middle + 1, end, target);
            }
        }
        else {
            return confirmRow(nums, begin, middle - 1, target);
        }
    }

    bool search(vector<int>& nums, int begin, int end, int target) { // ��һ���ж��ֲ���
        if (begin > end) {
            return false;
        }
        int middle = (begin + end) / 2;

        if (target > nums[middle]) {
            return search(nums, middle + 1, end, target);
        }
        else if (target < nums[middle]) {
            return search(nums, begin, middle - 1, target);
        }
        else {
            return true;
        }
    }
};