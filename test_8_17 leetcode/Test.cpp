#define _CRT_SECURE_NO_WARNINGS 1

//检查数组是否存在有效划分
class Solution {
public:
    bool validPartition(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[1] = (nums[0] == nums[1]);
        if (n == 2)
            return dp[1];
        dp[2] = (nums[0] == nums[1] && nums[1] == nums[2]) || (nums[2] == nums[1] + 1 && nums[1] == nums[0] + 1);

        for (int i = 3; i < n; ++i)
        {
            dp[i] = (dp[i - 2] && nums[i] == nums[i - 1]) || (dp[i - 3] && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                || (dp[i - 3] && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1);
        }
        return dp[n - 1];
    }
};

//最长理想子序列
//方法1：二维dp
 class Solution {
 public:
     int longestIdealString(string s, int k)
     {
         int n = s.size();
         vector<vector<int>> dp(n+1, vector<int>(26, 0));
         for(int i = 1; i <= n; ++i)
         {
             int x = s[i-1] - 'a';
             for(int j = 0; j < 26; ++j)
             {
                 dp[i][j] = dp[i-1][j];
             }

             for(int j = max(0, x-k); j < min(26, x+k+1); ++j)
             {
                 dp[i][x] = max(dp[i-1][j]+1, dp[i][x]);
             }
         }
         int ans = 0;
         for(int i = 0; i < 26; ++i)
         {
             ans = max(ans, dp[n][i]);
         }
         return ans;            
     }
 };

 //方法2：降维优化后
 class Solution {
 public:
     int longestIdealString(string s, int k)
     {
         int n = s.size();
         int dp[26] = { 0 };
         for (int i = 1; i <= n; ++i)
         {
             int x = s[i - 1] - 'a';
             dp[x] = *max_element(dp + max(0, x - k), dp + min(26, x + k + 1)) + 1;
         }
         return *max_element(dp, dp + 26);
     }
 };