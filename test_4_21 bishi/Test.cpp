#define _CRT_SECURE_NO_WARNINGS 1

//小易的升级之路
#include <iostream>
#include <vector>
using namespace std;

int GreatestCommonDivisor(int x, int y)
{
    int tmp = 0;
    while (y > 0)
    {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

int main()
{
    int n, a;
    while (cin >> n >> a)
    {
        vector<int> defense(n);
        for (int i = 0; i < defense.size(); ++i)
            cin >> defense[i];
        int c = a;
        for (int i = 0; i < defense.size(); ++i)
        {
            if (c >= defense[i])
                c += defense[i];
            else
                c += GreatestCommonDivisor(c, defense[i]);
        }
        cout << c << endl;
    }
    return 0;
}

//字符串中第一个只出现一次的字符
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a[128] = { 0 };
    for (int i = 0; i < s.size(); ++i)
    {
        ++a[s[i]];
    }
    int flag = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (a[s[i]] == 1)
        {
            flag = 0;
            cout << s[i] << endl;
            break;
        }
    }
    if (flag == 1)
        cout << -1 << endl;
    return 0;
}