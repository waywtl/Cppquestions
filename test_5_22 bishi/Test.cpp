#define _CRT_SECURE_NO_WARNINGS 1

//Ω‚∂¡√‹¬Î
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        string ret;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
                ret += s[i];
        }
        cout << ret << endl;
    }
    return 0;
}

//◊ﬂ√‘π¨
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<char>>& vv, int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    int arr[4][2] = { {-1, 0},{1, 0},{0, -1},{0, 1} };
    int size = 1;
    int step = 0;
    while (!q.empty())
    {
        while (size--)
        {
            for (int i = 0; i < 4; ++i)
            {
                int newX = q.front().first + arr[i][0];
                int newY = q.front().second + arr[i][1];
                if (x < 0 || x >= 10 || y < 0 || y >= 10)
                    continue;
                if (vv[newX][newY] == '.')
                {
                    q.push(make_pair(newX, newY));
                    vv[newX][newY] = '#';
                }
                if (newX == 9 && newY == 8)
                    return step + 1;
            }
            q.pop();
        }
        size = q.size();
        ++step;
    }
    return 0;
}

int main()
{
    vector<vector<char>> vv(10, vector<char>(10));
    while (cin >> vv[0][0])
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                cin >> vv[i][j];
            }
        }
        cout << bfs(vv, 0, 1) << endl;
    }
}