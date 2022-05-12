#define _CRT_SECURE_NO_WARNINGS 1

//减花布条
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s2.size() > s1.size())
        {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (i < s1.size())
        {
            j = 0;
            int prev = i;
            while (i < s1.size() && j < s2.size() && s1[i] == s2[j])
            {
                ++j;
                ++i;
            }
            if (j == s2.size())
                ++cnt;
            else
                i = prev + 1;
        }
        cout << cnt << endl;
    }
    return 0;
}

//客似云来
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int start, end;
    while (cin >> start >> end)
    {
        vector<long long int> dp(81, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < dp.size(); ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        long long int sum = 0;
        for (int i = start; i <= end; ++i)
        {
            sum += dp[i];
        }
        cout << sum << endl;
    }
    return 0;
}