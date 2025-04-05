/*�����������в���Ԫ�صĵ�һ�������һ��Ԫ��*/
//����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//��������в�����Ŀ��ֵ target������[-1, -1]��
//�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { // ���ö��ֲ����ҵ���Ԫ�أ��ٴӸ�Ԫ�طֱ���ǰ���Ⱥ���ֲ���
        int n = nums.size();
        int find = search(nums, 0, n - 1, target);
        if (find == -1) {
            return { -1, -1 };
        }
        int begin = find, end = find;
        for (int temp = begin; temp != -1;) { // ��Ŀ��Ԫ�ص�ǰһ��Ԫ�ؿ�ʼ��ǰ���ֲ��ң�����Ҳ���Ŀ��Ԫ�ؼ�ֹͣ��ȷ����һ��Ԫ��
            begin = temp;
            temp = search(nums, 0, temp - 1, target);
        }
        for (int temp = end; temp != -1;) { // ��Ŀ��Ԫ�صĺ�һ��Ԫ�ؿ�ʼ�Ⱥ���ֲ��ң�����Ҳ���Ŀ��Ԫ�ؼ�ֹͣ��ȷ�����һ��Ԫ��
            end = temp;
            temp = search(nums, temp + 1, n - 1, target);
        }

        return { begin, end };
    }

    int search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) {
            return -1;
        }
        int middle = begin + (end - begin) / 2;
        int val = nums[middle];
        if (target > val) {
            return search(nums, middle + 1, end, target);
        }
        else if (target < val) {
            return search(nums, begin, middle - 1, target);
        }
        else {
            return middle;
        }
    }
};