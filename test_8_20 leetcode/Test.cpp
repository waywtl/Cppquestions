#define _CRT_SECURE_NO_WARNINGS 1

//根据身高重建队列
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2)
            {
                if (v1[0] == v2[0])
                    return v1[1] > v2[1];
                else
                    return v1[0] < v2[0];
            });
        int n = people.size();
        vector<vector<int>> ans(n, vector<int>(2, -1));
        for (int i = 0; i < n; ++i)
        {
            int pre = 0;
            for (int j = 0; j < n; ++j)
            {
                if (pre == people[i][1] && ans[j][0] == -1)
                {
                    ans[j] = people[i];
                    break;
                }
                if (ans[j][0] == -1)
                    ++pre;
            }
        }
        return ans;
    }
};

//分割等和子集
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int total = 0;
        int n = nums.size();
        int target = 0;
        for (auto& x : nums)
            total += x;
        if (total % 2 != 0)
            return false;
        target = total / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        dp[0][0] = true;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < target + 1; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j == nums[i])
                {
                    dp[i][j] = true;
                    continue;
                }
                if (j > nums[i])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
        return dp[n - 1][target];
    }
};