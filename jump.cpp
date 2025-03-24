/*��Ծ��Ϸ*/
//����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��
//ÿ��Ԫ�� nums[i] ��ʾ������ i �����ת����󳤶ȡ����仰˵��������� nums[i] �����������ת������ nums[i + j] ��:
//0 <= j <= nums[i]
//i + j < n
//���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]��
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int i = 0;
        while (i < n - 1) {
            int maxStep = i;
            int nextStep = 0;
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                if (i + j + nums[i + j] > maxStep) {
                    maxStep = i + j + nums[i + j];
                    nextStep = i + j;
                }
                if (i + j == n - 1) {
                    nextStep = i + j;
                }
            }
            i = nextStep;
            step++;

            if (nextStep >= n - 1) {
                break;
            }
        }
        return step;
    }
};