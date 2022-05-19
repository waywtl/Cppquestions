#define _CRT_SECURE_NO_WARNINGS 1

//发邮件
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    long long dp[21] = { 0,0,1 };
    for (int i = 3; i < 21; ++i)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}

//最长递增子序列
//方法1: O(n2)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        vector<int> dp(n, 0);
        dp[0] = 1;
        int maxLen = dp[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (v[i] > v[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        cout << maxLen << endl;
    }
    return 0;
}

//方法2:O(nlogn)
//d[i]:长度为i的递增子序列中，末尾元素的最小值
int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        vector<int> d(n + 1, 0);
        int len = 1;
        d[1] = v[0];

        for (int i = 1; i < n; ++i)
        {
            if (v[i] > d[len])
                d[++len] = v[i];
            else
            {
                int left = 1;
                int right = len;
                int pos = 0;
                while (left <= right)
                {
                    int mid = (left + right) >> 1;
                    if (d[mid] < v[i])
                    {
                        pos = mid;
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                d[pos + 1] = v[i];
            }
        }
        return len;
    }
}