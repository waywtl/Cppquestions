#define _CRT_SECURE_NO_WARNINGS 1

//密码破译
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= 65 && s[i] <= 90)
            {
                if (s[i] >= 65 && s[i] <= 69)
                {
                    s[i] = s[i] + 21;
                }
                else
                    s[i] = s[i] - 5;
            }
        }
        cout << s << endl;
    }
    return 0;
}

//因子个数
//方法1：列举出所有质数
#include <iostream>
#include <vector>
using namespace std;

void GetPrimeNum(vector<int>& v)
{
    for (int i = 2; i < 100000; ++i)
    {
        int flag = 1;
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag != 0)
            v.push_back(i);
    }
}

int main()
{
    int n = 0;
    vector<int> v;
    GetPrimeNum(v);
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 0; i < v.size() && n != 1; ++i)
        {
            while (n % v[i] == 0)
            {
                n /= v[i];
            }
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}

//方法2：直接判断
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 2; i < sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;
                ++cnt;
            }
        }
        if (n != 1)
            ++cnt;
        cout << cnt << endl;
    }
    return 0;
}