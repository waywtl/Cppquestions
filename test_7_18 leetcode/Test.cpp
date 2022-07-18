#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//最长有效括号
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        int num = 0;
        int ans = 0;
        for (int i = 1; i < n + 1; ++i)
        {
            if (i == 1 && s[i - 1] == ')')
                continue;

            if (s[i - 1] == ')')
            {
                if (s[i - 2] == '(')
                    dp[i] = dp[i - 2] + 2;
                else
                {
                    if (num > 0)
                        dp[i] = (dp[i - 1] + 2) + dp[i - dp[i - 1] - 2];
                }
                num = ((num == 0) ? 0 : (num - 1));
                ans = max(ans, dp[i]);
            }
            else
                ++num;
        }
        return ans;
    }
};