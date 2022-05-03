#define _CRT_SECURE_NO_WARNINGS 1

//哔哩哔哩2020校园招聘技术类笔试卷（二）
//https://www.nowcoder.com/test/20725660/summary

//复数乘法
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string ret;
    string s1_re, s1_im, s2_re, s2_im;
    for (int i = 0; i <= s1.size(); ++i)
    {
        if (i == s1.size())
        {
            if (s1[s1.size() - 1] == 'i')
            {
                s1_re = "0";
                s1_im = s1;
                s1_im.pop_back();
            }
            else
            {
                s1_re = s1;
                s1_im = "0";
            }
        }
        if (s1[i] == '+')
        {
            s1_re = s1.substr(0, i);
            s1_im = s1.substr(i + 1);
            s1_im.pop_back();
            if (s1_im == "")
                s1_im = "1";
            break;
        }
    }
    for (int i = 0; i <= s2.size(); ++i)
    {
        if (i == s2.size())
        {
            if (s2[s2.size() - 1] == 'i')
            {
                s2_re = "0";
                s2_im = s2;
                s2_im.pop_back();
            }
            else
            {
                s2_re = s2;
                s2_im = "0";
            }
        }
        if (s2[i] == '+')
        {
            s2_re = s2.substr(0, i);
            s2_im = s2.substr(i + 1);
            s2_im.pop_back();
            if (s2_im == "")
                s2_im = "1";
            break;
        }
    }
    int num1_re = stoi(s1_re);
    int num1_im = stoi(s1_im);
    int num2_re = stoi(s2_re);
    int num2_im = stoi(s2_im);
    int re = num1_re * num2_re - num1_im * num2_im;
    int im = num1_re * num2_im + num1_im * num2_re;
    ret += to_string(re);
    ret += '+';
    ret += to_string(im);
    ret += 'i';
    cout << ret << endl;
    return 0;
}

//一年中的第几天
#include <iostream>
#include <string>
using namespace std;

int GetDay(int year, int month)
{
    int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int ret = day[month];
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
        ret += 1;
    return ret;
}
int main()
{
    string date;
    cin >> date;
    int cnt = 0;
    string str_year, str_month, str_day;
    str_year = date.substr(0, 4);
    str_month = date.substr(5, 2);
    str_day = date.substr(8);
    int ret = 0;
    int year = stoi(str_year);
    int month = stoi(str_month);
    int day = stoi(str_day);
    for (int i = 1; i < month; ++i)
    {
        ret += GetDay(year, i);
    }
    ret += day;
    cout << ret << endl;
    return 0;
}

//k个一组翻转链表
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v;
    while (1)
    {
        string num;
        cin >> num;
        if (num != "#")
            v.push_back(stoi(num));
        else
            break;
    }
    int k = 0;
    cin >> k;
    auto it = v.begin();
    while (it <= v.end() - k)
    {
        reverse(it, it + k);
        it += k;
    }
    string ret;
    for (int i = 0; i < v.size(); ++i)
    {
        ret += to_string(v[i]);
        ret += "->";
    }
    ret.pop_back();
    ret.pop_back();
    cout << ret << endl;
    return 0;
}