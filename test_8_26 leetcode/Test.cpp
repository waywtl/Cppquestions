#define _CRT_SECURE_NO_WARNINGS 1

//回文子串
class Solution {
public:
    int countSubstrings(string s)
    {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));

        for (int i = 0; i < len; ++i)
            dp[i][i] = true;

        int ans = len;
        for (int i = 1; i < len; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i - 1][j + 1] | (j + 1 == i);
                }

                if (dp[i][j])
                    ++ans;
            }
        }
        return ans;
    }
};

//每日温度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        stack<int> s;
        s.push(0);
        vector<int> ans(n, 0);
        for (int i = 1; i < n; ++i)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int j = s.top();
                s.pop();
                ans[j] = i - j;
            }
            s.push(i);
        }
        return ans;
    }
};