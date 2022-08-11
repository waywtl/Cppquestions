
//≤È’“–÷µ‹µ•¥ 
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
        vector<string> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        string target;
        int k = 0;
        cin >> target >> k;

        int num = 0;
        string ans;

        string s = target;
        sort(s.begin(), s.end());
        sort(v.begin(), v.end());
        for (auto str : v)
        {
            string sub = str;
            sort(sub.begin(), sub.end());
            if (str != target && sub == s)
            {
                if (++num == k)
                    ans = str;
            }
        }

        cout << num << endl << ans << endl;
    }
    return 0;
}

//∆π≈“«Úø
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (auto& ch : s1)
            ++m1[ch];
        for (auto& ch : s2)
            ++m2[ch];
        int flag = 0;
        auto it = m2.begin();
        while (it != m2.end())
        {
            if (m1.find(it->first) == m1.end() || (m1.find(it->first) != m1.end() && m1[it->first] < m2[it->first]))
            {
                flag = 1;
                cout << "No" << endl;
                break;
            }
            ++it;
        }
        if (flag == 0)
            cout << "Yes" << endl;
    }
    return 0;
}