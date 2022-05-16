#define _CRT_SECURE_NO_WARNINGS 1

//数据库连接池
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

        int ret = 0;
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i][2] == 'c')
                ++cnt;
            else
            {
                ret = max(ret, cnt);
                --cnt;
            }
        }
        cout << ret << endl;
    }
    return 0;
}

//mkdir
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<string> v;
        v.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());
        for (int i = 1; i < n; ++i)
        {
            if (v[i].find(v[i - 1]) != string::npos)
            {
                int len = v[i - 1].size();
                if (v[i][len] == '/')
                    v[i - 1] = " ";
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != " ")
                cout << "mkdir -p " << v[i] << endl;
        }
        cout << endl;
    }
    return 0;
}