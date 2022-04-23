#define _CRT_SECURE_NO_WARNINGS 1

//√‘π¨Œ Ã‚
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> row;
vector<int> col;

void Print()
{
    for (int i = 0; i < row.size(); ++i)
    {
        printf("(%d,%d)\n", row[i], col[i]);
    }
}

void dfs(int x, int y, vector<vector<int>>& maze)
{
    maze[x][y] = 1;

    row.push_back(x);
    col.push_back(y);
    if (x == n - 1 && y == m - 1)
    {
        Print();
        return;
    }

    if (x - 1 >= 0 && maze[x - 1][y] == 0)
        dfs(x - 1, y, maze);
    if (x < n - 1 && maze[x + 1][y] == 0)
        dfs(x + 1, y, maze);
    if (y - 1 >= 0 && maze[x][y - 1] == 0)
        dfs(x, y - 1, maze);
    if (y < m - 1 && maze[x][y + 1] == 0)
        dfs(x, y + 1, maze);

    row.pop_back();
    col.pop_back();

    maze[x][y] = 0;
    return;
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }
    dfs(0, 0, maze);
    return 0;
}