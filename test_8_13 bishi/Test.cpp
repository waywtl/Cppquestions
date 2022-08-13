#define _CRT_SECURE_NO_WARNINGS 1

// 合唱团
// 方法一:递归，不能ac, 80%通过, 对于特殊数据时间复杂度太高
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void dfs(vector<int>& v, int start, int end, int k, int d, int n, int cnt, long long mul, long long* ans)
{
    if (cnt == k)
    {
        *ans = max(*ans, mul);
        return;
    }
    for (int i = start; i <= end && i < n; ++i)
    {
        dfs(v, i + 1, i + d, k, d, n, cnt + 1, mul * v[i], ans);
    }
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int k = 0;
        int d = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        cin >> k >> d;

        long long mul = 1;
        long long ans = LLONG_MIN;
        dfs(v, 0, n - k, k, d, n, 0, mul, &ans);
        cout << ans << endl;
    }
    return 0;
}

// 方法2: 动态规划 ac
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef long long ll;

ll ans = LLONG_MIN;

void solve(const vector<ll>& v, int n, int kk, int dd)
{
    vector<vector<ll>> dpMax(n, vector<ll>(kk + 1, 0));
    vector<vector<ll>> dpMin(n, vector<ll>(kk + 1, 0));

    for (int i = 0; i < n; ++i)
    {
        dpMax[i][1] = v[i];
        dpMin[i][1] = v[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = 2; k <= min(kk, i + 1); ++k)
        {
            for (int j = max(0, i - dd); j < i; ++j)
            {
                dpMax[i][k] = max(dpMax[i][k], max(dpMax[j][k - 1] * v[i], dpMin[j][k - 1] * v[i]));
                dpMin[i][k] = min(dpMin[i][k], min(dpMax[j][k - 1] * v[i], dpMin[j][k - 1] * v[i]));
            }
        }
        ans = max(ans, dpMax[i][kk]);
    }
    cout << ans << endl;
    return;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int kk = 0;
        int dd = 0;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        cin >> kk >> dd;

        solve(v, n, kk, dd);
    }
    return 0;
}

//马戏团
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<pair<int, int>> v(n);
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
            {
                if (p1.first != p2.first)
                    return p1.first < p2.first;
                else
                    return p1.second > p2.second;
            });

        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            int len = 1;
            for (int j = 0; j < i; ++j)
            {
                if (v[i].second >= v[j].second)
                    len = max(len, dp[j] + 1);
            }
            dp[i] = len;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}