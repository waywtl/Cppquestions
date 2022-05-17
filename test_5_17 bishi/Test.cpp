#define _CRT_SECURE_NO_WARNINGS 1

//ºìÓëºÚ
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& vv, int m, int n, int x, int y, int& cnt)
{
    if (x < 0 || x >= m || y < 0 || y >= n || vv[x][y] == '#')
        return;
    vv[x][y] = '#';
    ++cnt;
    dfs(vv, m, n, x - 1, y, cnt);
    dfs(vv, m, n, x, y + 1, cnt);
    dfs(vv, m, n, x + 1, y, cnt);
    dfs(vv, m, n, x, y - 1, cnt);
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<char>> vv(m, vector<char>(n, '0'));
        int x = 0;
        int y = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> vv[i][j];
                if (vv[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        int cnt = 0;
        dfs(vv, m, n, x, y, cnt);
        cout << cnt << endl;
    }
    return 0;
}

//Ä¢¹½Õó
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int x, y;
        vector<vector<int>> vv(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            vv[x][y] = 1;
        }

        vector<vector<float>> dp(n + 1, vector<float>(m + 1, 0));
        dp[1][1] = 1.0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (i == 1 && j == 1)
                    continue;
                else
                {
                    float pi = (i == n) ? 1 : 0.5;
                    float pj = (j == m) ? 1 : 0.5;
                    dp[i][j] = dp[i][j - 1] * pi + dp[i - 1][j] * pj;

                    if (vv[i][j] == 1)
                        dp[i][j] = 0;
                }
            }
        }
        printf("%.2f\n", dp[n][m]);
    }
    return 0;
}