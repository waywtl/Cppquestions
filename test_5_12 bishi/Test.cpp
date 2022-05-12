#define _CRT_SECURE_NO_WARNINGS 1

//收件人列表
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        getchar();
        vector<string> v;
        v.resize(n);
        for (int i = 0; i < n; ++i)
            getline(cin, v[i]);
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[i].size(); ++j)
            {
                if (v[i][j] == ' ' || v[i][j] == ',')
                {
                    v[i].insert(v[i].begin(), '"');
                    v[i].push_back('"');
                    break;
                }
            }
        }
        for (int i = 0; i < v.size() - 1; ++i)
            cout << v[i] << ", ";
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}

//养兔子
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    long long int dp[91] = { 0 };
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 91; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}