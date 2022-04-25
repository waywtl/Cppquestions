#define _CRT_SECURE_NO_WARNINGS 1

//–«º √‹¬Î
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = { 1, 1 };
    for (int i = 2; i < 10001; ++i)
        v.push_back((v[i - 1] + v[i - 2]) % 10000);
    int n = 0;
    while (cin >> n)
    {
        vector<int> code(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> code[i];
            printf("%04d", v[code[i]]);
        }
        cout << endl;
    }
    return 0;
}

// ˝∏˘
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string NumberRoot(string s)
{
    if (s.size() == 1)
        return s;
    int n = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        n += s[i] - '0';
    }
    return NumberRoot(to_string(n));
}

int main()
{
    string s;
    while (cin >> s)
    {
        string ret = NumberRoot(s);
        cout << ret << endl;
    }
    return 0;
}