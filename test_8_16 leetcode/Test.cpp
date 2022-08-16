#define _CRT_SECURE_NO_WARNINGS 1

//戳气球
//方法1：暴力 O(n!)  不能ac
 class Solution {
 public:
     int max_coins = 0;
     void solve(vector<int>& nums, int n, vector<int>& book, int& k, int coins_cnt)
     {
         if(k == n-2)
         {
             max_coins = max(max_coins, coins_cnt);
             return;
         }
         for(int i = 1; i < n-1; ++i)
         {
             if(book[i] == 0)
                 continue;
             book[i] = 0;
             int left_coin = i-1;
             while(left_coin >= 0 && book[left_coin] == 0)
                 --left_coin;
             int right_coin = i+1;
             while(right_coin <= n-1 && book[right_coin] == 0)
                 ++right_coin;
             int cur_coins = nums[left_coin]*nums[i]*nums[right_coin];
             solve(nums, n, book, ++k, coins_cnt+cur_coins);
             --k;
             book[i] = 1;
         }
     }

     int maxCoins(vector<int>& nums)
     {
         nums.insert(nums.begin(), 1);
         nums.push_back(1);
         int n = nums.size();
         vector<int> book(n, 1);
         int k = 0;
         solve(nums, n, book, k, 0);
         return max_coins;
     }
 };

 //方法2: 动态规划  O(n3) ac
 class Solution {
 public:
     int maxCoins(vector<int>& nums)
     {
         int n = nums.size();
         vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
         vector<int> tmp(n + 2);
         for (int i = 0; i < n; ++i)
         {
             tmp[i + 1] = nums[i];
         }
         tmp[0] = 1;
         tmp[n + 1] = 1;

         for (int len = 3; len <= n + 2; ++len)
         {
             for (int l = 0; l <= n + 2 - len; ++l)
             {
                 for (int k = l + 1; k < l + len - 1; ++k)
                 {
                     int left = dp[l][k];
                     int right = dp[k][l + len - 1];
                     int sum = left + right + tmp[l] * tmp[k] * tmp[l + len - 1];
                     dp[l][l + len - 1] = max(dp[l][l + len - 1], sum);
                 }
             }
         }
         return dp[0][n + 1];
     }
 };