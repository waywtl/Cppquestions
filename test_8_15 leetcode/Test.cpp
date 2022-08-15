#define _CRT_SECURE_NO_WARNINGS 1

//最佳买卖股票时机含冷冻期
//方法1：dp  O(n)空间复杂度
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        dp[1][1] = max(dp[0][1], -prices[1]);

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            if(i > 1)
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

//方法2：空间优化  O(1)空间复杂度
 class Solution {
 public:
     int maxProfit(vector<int>& prices)
     {
         int n = prices.size();
         int sell = 0;
         int buy = -prices[0];
         int profit_freeze = 0;

         for(int i = 1; i < n; ++i)
         {
             int tmp = sell;
             sell = max(sell, buy+prices[i]);
             buy = max(buy, profit_freeze - prices[i]);
             //保存2天前的sell
             profit_freeze = tmp;
         }
         return sell;
     }
 };