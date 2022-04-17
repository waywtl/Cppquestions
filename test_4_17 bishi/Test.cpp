#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//×Ö·û´®Í¨Åä·û
void lower(string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (isupper(str[i]))
            str[i] += 32;
    }
}

int StringMatch(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < len2 + 1; ++i)
        dp[0][i] = 0;
    for (int i = 1; i < len1 + 1; ++i)
    {
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == '*');
        for (int j = 1; j < len2 + 1; ++j)
        {
            if (s1[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] && (s1[i - 1] == s2[j - 1] || (s1[i - 1] == '?' && isalnum(s2[j - 1])));
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lower(s1);
    lower(s2);
    int ret = StringMatch(s1, s2);
    if (ret == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}