/*���������*/
//����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
//������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ���������ִ����ϣ����
        unordered_set<int> rank(nums.begin(), nums.end());
        int longest = 0;

        // ������ϣ����
        for (int num : rank) {
            // �����ǰ�������������е����
            if (rank.find(num - 1) == rank.end()) {
                int currentNum = num;
                int currentLength = 1;

                // ��չ��������
                while (rank.find(currentNum + 1) != rank.end()) {
                    currentNum++;
                    currentLength++;
                }

                // ��������г���
                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};