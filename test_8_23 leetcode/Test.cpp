#define _CRT_SECURE_NO_WARNINGS 1

//找到所有数组中消失的数字
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> ret;
        int n = nums.size();
        for (auto& num : nums)
        {
            int x = (num - 1) % n;
            nums[x] += n;
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= n)
                ret.push_back(i + 1);
        }
        return ret;
    }
};

//汉明距离
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y);
    }
};

//目标和
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (auto& x : nums)
            sum += x;
        if (abs(target) > sum)
            return 0;

        int t = 2 * sum + 1;
        vector<vector<int>> dp(n, vector<int>(t, 0));

        dp[0][sum + nums[0]] += 1;
        dp[0][sum - nums[0]] += 1;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < t; ++j)
            {
                if (j >= nums[i])
                    dp[i][j] += dp[i - 1][j - nums[i]];
                if (j + nums[i] < t)
                    dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }
        return dp[n - 1][target + sum];
    }
};