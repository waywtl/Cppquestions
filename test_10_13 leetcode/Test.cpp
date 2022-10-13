#define _CRT_SECURE_NO_WARNINGS 1

//矩阵中和能被 K 整除的路径
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        int f[m + 1][n + 1][k];
        memset(f, 0, sizeof(f));
        f[1][0][0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int t = 0; t < k; ++t)
                {
                    f[i][j][(t + grid[i - 1][j - 1]) % k] = (f[i - 1][j][t] + f[i][j - 1][t]) % MOD;
                }
            }
        }
        return f[m][n][0];
    }
};

//地宫取宝
#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 55;
const int K = 15;

int a[N][N];
int f[N][N][K][K];

int main()
{
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            a[i][j] += 1;
        }
    }

    f[1][1][0][0] = 1;
    f[1][1][1][a[1][1]] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int cnt = 0; cnt <= k; ++cnt)
            {
                for (int v = 0; v < K; ++v)
                {
                    //不拿
                    f[i][j][cnt][v] = (f[i][j][cnt][v] + f[i - 1][j][cnt][v]) % MOD;
                    f[i][j][cnt][v] = (f[i][j][cnt][v] + f[i][j - 1][cnt][v]) % MOD;

                    //拿
                    if (cnt > 0 && a[i][j] == v)
                    {
                        for (int s = 0; s < v; ++s)
                        {
                            f[i][j][cnt][v] = (f[i][j][cnt][v] + f[i - 1][j][cnt - 1][s]) % MOD;
                            f[i][j][cnt][v] = (f[i][j][cnt][v] + f[i][j - 1][cnt - 1][s]) % MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int s = 1; s < K; ++s)
    {
        ans = (ans + f[n][m][k][s]) % MOD;
    }

    cout << ans << endl;

    return 0;
}