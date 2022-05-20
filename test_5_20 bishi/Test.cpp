#define _CRT_SECURE_NO_WARNINGS 1

//五子棋
#include <iostream>
#include <vector>
using namespace std;

/*bool IsWin(vector<vector<char>>& vv, int x, int y)
{
    char ch = vv[x][y];
    int colCnt = 1;
    for (int i = x - 1; i >= 0; --i)
    {
        if (vv[i][y] == ch)
            ++colCnt;
        else
            break;
    }
    for (int i = x + 1; i < 20; ++i)
    {
        if (vv[i][y] == ch)
            ++colCnt;
        else
            break;
    }
    if (colCnt >= 5)
        return true;

    int rowCnt = 1;
    for (int i = y - 1; i >= 0; --i)
    {
        if (vv[x][i] == ch)
            ++rowCnt;
        else
            break;
    }
    for (int i = y + 1; i < 20; ++i)
    {
        if (vv[x][i] == ch)
            ++rowCnt;
        else
            break;
    }
    if (rowCnt >= 5)
        return true;

    int leftCnt = 1;
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (vv[i][j] == ch)
            ++leftCnt;
        else
            break;
    }
    for (int i = x + 1, j = y + 1; i < 20 && j < 20; ++i, ++j)
    {
        if (vv[i][j] == ch)
            ++leftCnt;
        else
            break;
    }
    if (leftCnt >= 5)
        return true;

    int rightCnt = 1;
    for (int i = x - 1, j = y + 1; i >= 0 && j < 20; --i, ++j)
    {
        if (vv[i][j] == ch)
            ++rightCnt;
        else
            break;
    }
    for (int i = x + 1, j = y - 1; i < 20 && j >= 0; ++i, --j)
    {
        if (vv[i][j] == ch)
            ++rightCnt;
        else
            break;
    }
    if (rightCnt >= 5)
        return true;
    return false;
}

int main()
{
    vector<vector<char>> vv(20, vector<char>(20));
    while (cin >> vv[0][0])
    {
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                cin >> vv[i][j];
            }
        }
        bool ret = false;
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                if (vv[i][j] != '.')
                    ret = IsWin(vv, i, j);
            }
        }
        if (ret)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}*/

//Emacs计算器
//后缀表达式
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int ops(string s, int x, int y)
{
    char op = s[0];
    int ret = 0;
    switch (op)
    {
    case '+':
        ret = x + y;
        break;
    case '-':
        ret = x - y;
        break;
    case '*':
        ret = x * y;
        break;
    case '/':
        ret = x / y;
        break;
    default:
        break;
    }
    return ret;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<string> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int ret = 0;
        stack<int> dataSt;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/")
                dataSt.push(stoi(v[i]));
            else
            {
                int y = dataSt.top();
                dataSt.pop();
                int x = dataSt.top();
                dataSt.pop();
                int num = ops(v[i], x, y);
                dataSt.push(num);
            }
        }
        cout << dataSt.top() << endl;
    }
    return 0;
}