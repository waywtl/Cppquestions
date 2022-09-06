#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//统计子串中的唯一字符
//方法1：暴力 不能ac
class Solution {
public:
    vector<string> sub;
    int n = 0;
    int ans = 0;
    string str;

    void dfs(string cur, int i)
    {
        if (i == n + 1)
            return;
        sub.push_back(cur);
        dfs(cur + str[i], i + 1);
    }

    void solve(const string& s)
    {
        unordered_map<char, int> m;
        for (auto& ch : s)
            ++m[ch];

        for (auto& p : m)
        {
            if (p.second == 1)
                ++ans;
        }
    }

    int uniqueLetterString(string s)
    {
        n = s.size();
        str = s;
        string ss = "";
        for (int i = 0; i < n; ++i)
            dfs(ss + str[i], i + 1);

        for (int i = 0; i < sub.size(); ++i)
            solve(sub[i]);

        return ans;
    }
};

//方法2：乘法原理: 记录每个字符出现的位置
//单个字符贡献的次数为 (i(当前的位置) - j(前一次的位置)) * (k(后一次的位置) - i(当前的位置))
class Solution {
public:
    int uniqueLetterString(string s)
    {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < s.size(); ++i)
            m[s[i]].push_back(i);

        int ans = 0;
        int n = s.size();
        for (auto& p : m)
        {
            vector<int> v = p.second;
            v.insert(v.begin(), -1);
            v.push_back(n);

            for (int i = 1; i < v.size() - 1; ++i)
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
        }

        return ans;
    }
};

//最长递增子序列的个数
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int ans = 0;
        int max_len = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                ans = cnt[i];
            }
            else if (dp[i] == max_len)
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

//三次操作后最大值与最小值的最小差
class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        if (nums.size() <= 4)
            return 0;
        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        for (auto& x : nums)
        {
            q1.push(x);
            q2.push(x);
        }

        int ans = INT_MAX;
        vector<int> v1(4), v2(4);
        for (int i = 0; i < 4; ++i)
        {
            v1[3 - i] = q1.top();
            v2[i] = q2.top();
            q1.pop();
            q2.pop();
        }

        for (int i = 0; i < 4; ++i)
            ans = min(ans, v1[i] - v2[i]);
        return ans;
    }
};