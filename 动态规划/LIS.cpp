/*�����������*/
//����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
//������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3, 6, 2, 7] ������[0, 3, 1, 6, 2, 2, 7] �������С�
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 1);
        int max_len = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};