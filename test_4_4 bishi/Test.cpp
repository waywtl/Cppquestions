#define _CRT_SECURE_NO_WARNINGS 1

//解析字符串
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int i = 0;
    int j = 0;
    int cnt = 0;
    vector<string> vs;
    while (j <= str.size())
    {
        string ret(" ");
        if (j < str.size() && str[j] == '"')
        {
            i = ++j;
            while (str[j] != '"')
            {
                ++j;
            }
            ret = str.substr(i, j - i);
            vs.push_back(ret);
            ++cnt;
            i = (j += 2);
        }
        else if (j < str.size() && str[j] != ' ')
        {
            ++j;
        }
        else
        {
            ret = str.substr(i, j - i);
            vs.push_back(ret);
            ++cnt;
            i = ++j;
        }
    }
    cout << cnt << endl;
    for (auto e : vs)
        cout << e << endl;
    return 0;
}

//约数跳石板
//O(n2)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 0;
    int M = 0;
    cin >> N;
    cin >> M;
    int minSep = 0;
    if (M == N)
        cout << minSep << endl;
    vector<int> dp(M + 1, 0);
    for (int i = N + 1; i < dp.size(); ++i)
    {
        int sep = 0;
        minSep = M;
        for (int j = i - 1; j >= N; --j)
        {
            if (i - j > j / 2)
                break;
            if (dp[j] != -1 && (j % i-j == 0))
            {
                sep = dp[j] + 1;
                minSep = min(minSep, sep);
            }
        }
        if (sep != 0)
            dp[i] = minSep;
        else
            dp[i] = -1;
    }
    cout << dp[M] << endl;
    return 0;
}

//O(nlogn)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 0;
    int M = 0;
    cin >> N;
    cin >> M;

    vector<int> dp(M + 1, M);
    dp[N] = 0;
    for (int i = N; i <= M; ++i)
    {
        if (dp[i] == M)
            continue;
        for (int j = 2; (j * j) <= i; ++j)
        {
            if (i % j == 0)
            {
                if (i + j <= M)
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                if (i + (i / j) <= M)
                    dp[i + (i / j)] = min(dp[i] + 1, dp[i + (i / j)]);
            }
        }
    }
    if (dp[M] == M)
        dp[M] = -1;
    cout << dp[M] << endl;
    return 0;
}
