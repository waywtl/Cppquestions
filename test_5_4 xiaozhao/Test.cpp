#define _CRT_SECURE_NO_WARNINGS 1

//递增子序列
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int first = v[0];
    int second = INT_MAX;
    for (int i = 1; i < n; ++i)
    {
        if (v[i] < first)
        {
            first = v[i];
            second = INT_MAX;
        }
        else if (v[i] > first && v[i] < second)
            second = v[i];
        else if (v[i] > second)
        {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}

//硬币划分
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int coins[] = { 1, 2, 5, 10 };
    vector<vector<int>> dp(5, vector<int>(n + 1, 0));
    for (int i = 1; i < 5; ++i)
        dp[i][0] = 1;
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i - 1]]) % 1000000007;
        }
    }
    cout << dp[4][n] << endl;
    return 0;
}