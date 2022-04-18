#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//最长公共子串
string LongestCommonSubsequence(string s1, string s2)
{
    if (s1.length() > s2.length())
        swap(s1, s2);
    int len1 = s1.length(), len2 = s2.length();
    int maxLen = 0, start = 0;
    vector<vector<int> >dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    start = i - maxLen;
                }
            }
        }
    string ret = s1.substr(start, maxLen);
    return ret;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string ret = LongestCommonSubsequence(s1, s2);
    cout << ret << endl;
    return 0;
}