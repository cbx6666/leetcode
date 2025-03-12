/*��Ծ��Ϸ*/
//����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false ��
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;  // ��ǰ�ܹ��������Զλ��

        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                // �����ǰλ���Ѿ��������ܹ��������Զλ�ã�˵���޷�����
                return false;
            }
            // �����ܹ��������Զλ��
            maxReach = max(maxReach, i + nums[i]);

            // ����ܹ��������һ��λ�ã����� true
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return false;
    }
};