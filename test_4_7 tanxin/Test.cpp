#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//买卖股票最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            if (prices[i] - prices[i - 1] > 0)
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

//跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int maxSep = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (i <= maxSep)
            {
                maxSep = max(maxSep, i + nums[i]);
                if (maxSep >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

//最少纸币
class Solution
{
public:
    int MinMoneyCnt(const vector<vector<int>>& moneyCnt, int money)
    {
        int cnt = 0;
        for (int i = moneyCnt.size() - 1; i >= 0; --i)
        {
            int curCnt = min(money / moneyCnt[i][0], moneyCnt[i][1]);
            cnt += curCnt;
            money -= moneyCnt[i][0] * curCnt;

            if (money == 0)
                return cnt;
        }
        return -1;
    }
};