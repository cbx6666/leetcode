/*买股票的最佳时机*/
//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择某一天买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回0。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        
        return profit;
    }
};
