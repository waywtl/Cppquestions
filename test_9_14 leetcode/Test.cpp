#define _CRT_SECURE_NO_WARNINGS 1

//删除某些元素后的数组平均值
class Solution {
public:
    double trimMean(vector<int>& arr)
    {
        int n = arr.size();
        int cnt = n * 0.05;

        double ans = 0;

        sort(arr.begin(), arr.end());

        double sum = 0;
        for (int i = cnt; i < n - cnt; ++i)
        {
            sum += arr[i];
        }

        ans = sum / (n - 2 * cnt);
        return ans;
    }
};

//打家劫舍Ⅱ
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);

        dp[1] = nums[0];
        for (int i = 2; i < n; ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        int ans = dp[n - 1];

        dp[1] = 0;
        dp[2] = nums[1];
        for (int i = 3; i < n + 1; ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return max(ans, dp[n]);
    }
};