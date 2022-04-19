#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//最长公共子串的长度
int LongestCommonSequence(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int ret = 0;
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i < len1 + 1; ++i)
    {
        for (int j = 1; j < len2 + 1; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ret = max(dp[i][j], ret);
            }
        }
    }
    return ret;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int ret = LongestCommonSequence(s1, s2);
    cout << ret << endl;
    return 0;
}