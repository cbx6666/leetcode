/*�ƶ���*/
//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//��ע�� �������ڲ���������������ԭ�ض�������в�����
//ʾ�� 1:
//����: nums = [0, 1, 0, 3, 12]
//��� : [1, 3, 12, 0, 0]
//ʾ�� 2 :
//���� : nums = [0]
//��� : [0]
class Solution {
public:
    // ��һ���ύ��ʹ�ù�ϣ�����ӶȺܸ�...
    /*void moveZeroes(vector<int>& nums) {
        unordered_map<int, int> rank;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                rank[index] = nums[i];
                index++;
            }
        }
        int amountOfZero = nums.size() - index;
        for (int i = 0; i < index; i++) {
            nums[i] = rank[i];
        }
        for (int i = 0; i < amountOfZero; i++) {
            nums[i + index] = 0;
        }
    }*/

    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
