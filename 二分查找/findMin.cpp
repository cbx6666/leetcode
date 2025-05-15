/*Ѱ����ת���������е���Сֵ*/
//��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣
//���磬ԭ���� nums = [0,1,2,4,5,6,7] �ڱ仯����ܵõ���
//����ת 4 �Σ�����Եõ�[4, 5, 6, 7, 0, 1, 2]
//����ת 7 �Σ�����Եõ�[0, 1, 2, 4, 5, 6, 7]
//����һ��Ԫ��ֵ ������ͬ ������ nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�ء�
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int begin = 0, end = n - 1, min = 0;
        while (begin <= end) {
            int middle = begin + (end - begin) / 2;
            // ����������ȡbegin��Ϊ��Сֵ
            if (nums[middle] >= nums[begin] && nums[middle] <= nums[end]) {
                min = begin;
                break;
            }
            // ����������end - begin <= 1����ȡend��Ϊ��Сֵ
            if (end - begin <= 1) {
                min = end;
                break;
            }
            if (nums[middle] > nums[end]) {
                begin = middle;
            }
            if (nums[middle] < nums[begin]) {
                end = middle;
            }
        }

        return nums[min];
    }
};