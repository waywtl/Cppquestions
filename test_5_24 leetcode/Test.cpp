#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//正则表达式匹配
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int len1 = s.size();
        int len2 = p.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 2; i < len2 + 1; ++i)
        {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        for (int i = 1; i < len1 + 1; ++i)
        {
            for (int j = 1; j < len2 + 1; ++j)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                        dp[i][j] += dp[i - 1][j];
                    }
                }
                else
                {
                    if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        if (dp[len1][len2] >= 1)
            return true;
        else
            return false;
    }
};