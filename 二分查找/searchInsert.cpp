/*��������λ��*/
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return partition(nums, 0, nums.size() - 1, target);
    }

    int partition(vector<int>& nums,int start,int end,int target) {
        int n = nums.size();
        int middle = (start + end) / 2;

        if (start > end) { // �ڶ��ֲ����У��� start > end ʱ����ʾ���������Ѿ���Ч������Ϊ�գ�����ʱ����ȷ�� target �������������С�
            return start; // ����ʱ start ��ֵ��ʽ��ָ���� target Ӧ�ò����λ�ã�ʹ�ò����������Ȼ����(������ѧ֤��)��
        }

        if (target > nums[middle]) {
            return partition(nums, middle + 1, end, target);
        }
        else if (target < nums[middle]) {
            return partition(nums, start, middle - 1, target);
        }
        else {
            return middle;
        }
    }
};