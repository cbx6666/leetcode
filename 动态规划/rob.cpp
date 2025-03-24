/*��ҽ���*/
//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        dp[0] = nums[0], dp[1] = nums[1];
        int maxDp = dp[0];
        for (int i = 2; i < n; i++) {
            dp[i] = maxDp + nums[i];
            maxDp = maxDp > dp[i - 1] ? maxDp : dp[i - 1];
        }
        return maxDp > dp[n - 1] ? maxDp : dp[n - 1];
    }
};

