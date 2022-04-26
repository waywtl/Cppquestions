#define _CRT_SECURE_NO_WARNINGS 1

//快到碗里来
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Circumference(string& s)
{
    int cnt = 628;
    reverse(s.begin(), s.end());
    string tmp = s;
    int n = tmp.size();
    int carry = 0;
    int num = 0;
    while(cnt--)
    {
        string ret;
        for(int i = 0; i < s.size(); ++i)
        {
            int a = (i >= n) ? 0 : tmp[i]-'0';
            int sum = a + (s[i] - '0') + carry;
            num = sum % 10;
            carry = sum / 10;

            ret += to_string(num);
        }
        if(carry == 1)
        {
            ret += '1';
        }
        s = ret;
    }
    reverse(s.begin(), s.end());
}

int main()
{
    string n, r;
    while(cin >> n >> r)
    {
        n.push_back('0');
        n.push_back('0');
        Circumference(r);
        if(n.size() > r.size())
            cout << "No" << endl;
        else if(n.size() < r.size())
            cout << "Yes" << endl;
        else
        {
            for(int i = 0; i < n.size(); ++i)
            {
                if(n[i] > r[i])
                {
                    cout << "No" << endl;
                    break;
                }
                else if(n[i] < r[i])
                {
                    cout << "Yes" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

//方法2：
int main()
{
    double n, r;
    while (cin >> n >> r)
    {
        if (n <= r * 2 * 3.14)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}