/*��Ǯ�һ�*/
//����һ���������� coins ����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount ����ʾ�ܽ�
//���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��� �����û���κ�һ��Ӳ�����������ܽ����� - 1 ��
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; i++) {
            int min = dp[i];
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    min = min < dp[i - coins[j]] ? min : dp[i - coins[j]];
                }
            }
            if (min < INT_MAX) {
                dp[i] = min + 1;
            }
        }
        return dp[amount] < INT_MAX ? dp[amount] : -1;
    }
};