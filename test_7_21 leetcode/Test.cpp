#define _CRT_SECURE_NO_WARNINGS 1

//最大子数组和
//方法一：用dp来存储以当前数为结尾的最大连续和
//O(n)   O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i < n + 1; ++i)
        {
            if (dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i - 1];
            else
                dp[i] = nums[i - 1];

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//方法二：用变量sum来替换dp
//O(n)  O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

//最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

//爬楼梯
class Solution {
public:
    int climbStairs(int n)
    {
        int a = 1;
        int b = 1;
        int ans = 1;
        while (--n)
        {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

//颜色分类
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int arr[3] = { 0 };
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            ++arr[nums[i]];
        }
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            while (arr[j] <= 0)
                ++j;
            nums[i] = j;
            --arr[j];
        }
    }
};

//最小覆盖字串
class Solution {
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        string ans;
        if (s.size() < t.size())
            return ans;

        unordered_map<char, int> hs;
        unordered_map<char, int> ht;
        for (auto& ch : t)
            ++ht[ch];

        int cnt = 0;
        for (int i = 0, j = 0; i < n; ++i)
        {
            ++hs[s[i]];
            if (hs[s[i]] <= ht[s[i]])
                ++cnt;
            while (hs[s[j]] > ht[s[j]])
                --hs[s[j++]];

            if (cnt == t.size())
            {
                if (ans.size() == 0 || i - j + 1 < ans.size())
                    ans = s.substr(j, i - j + 1);
            }
        }
        return ans;
    }
};