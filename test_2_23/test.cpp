#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//反转字符串中的单词
class Solution {
public:
    string reverseWords(string s)
    {
        int start = 0;
        int end = 0;
        int i = 0;
        while (i < s.size())
        {
            while (s[i] != ' ' && i < s.size())
                ++i;
            end = i - 1;
            while (start < end)
            {
                swap(s[start], s[end]);
                ++start;
                --end;
            }
            ++i;
            start = i;
        }
        return s;
    }
};

//反转字符串
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int sz = s.size();
        for (int i = 0; i < sz; i += 2 * k)
        {
            int start = i;
            int end = start + k - 1;
            while (start < end)
            {
                if (end >= sz)
                    end = sz - 1;
                swap(s[start], s[end]);
                ++start;
                --end;
            }
        }
        return s;
    }
};