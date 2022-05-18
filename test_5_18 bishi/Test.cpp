#define _CRT_SECURE_NO_WARNINGS 1

//字符串计数
//方法1：动态规划
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    int len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2)
    {
        int arr[51] = { 0 };
        int k = 0;
        while (s1[k] == s2[k])
            ++k;
        arr[k + 1] = s2[k] - s1[k];
        for (int i = k + 2; i <= len2; ++i)
        {
            int stuff = 0;
            if (i <= s1.size())
                stuff += 'z' - s1[i - 1];
            if (i < s2.size())
                stuff -= 'z' - s2[i - 1];
            if (i == s2.size())
                stuff -= 'z' - s2[i - 1] + 1;

            arr[i] = arr[i - 1] * 26 + stuff;
        }
        int cnt = 0;
        for (int i = len1; i <= len2; ++i)
            cnt += arr[i];
        cout << cnt << endl;
    }
    return 0;
}

//方法2:26进制计算
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s1, s2;
    int len1, len2;
    while (cin >> s1 >> s2 >> len1 >> len2)
    {
        if (s1.size() < len2)
            s1.append('a', len2 - s1.size());
        if (s2.size() < len2)
            s2.append('z+1', len2 - s2.size());

        int arr[51] = { 0 };
        for (int i = 0; i < len2; ++i)
            arr[i] = s2[i] - s1[i];

        int cnt = 0;
        for (int i = len1; i <= len2; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                cnt += arr[j] * pow(26, i - j - 1);
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}

//最长公共子序列
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string m, n;
    while (cin >> m >> n)
    {
        int len1 = m.size();
        int len2 = n.size();
        vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

        for (int i = 1; i < len1 + 1; ++i)
        {
            for (int j = 1; j < len2 + 1; ++j)
            {
                if (m[i - 1] == n[j - 1])
                    vv[i][j] = vv[i - 1][j - 1] + 1;
                else
                    vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]);
            }
        }
        cout << vv[len1][len2] << endl;
    }
    return 0;
}