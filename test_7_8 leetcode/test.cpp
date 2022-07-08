#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//Z字形变换
class Solution {
public:
    string convert(string s, int numRows)
    {
        string ans;
        if (numRows == 1)
            return s;
        int size = s.size();
        vector<int> v(size, 0);
        int index = 1;
        int flag = 0;
        for (int i = 0; i < size; ++i)
        {
            v[i] = index;
            if (flag == 0)
            {
                ++index;
                if (index > numRows)
                {
                    index -= 2;
                    flag = 1;
                }
            }
            else
            {
                --index;
                if (index < 1)
                {
                    index += 2;
                    flag = 0;
                }
            }

        }
        for (int i = 1; i <= numRows; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (v[j] == i)
                    ans += s[j];
            }
        }
        return ans;
    }
};

//括号生成
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 1)
            return { "()" };
        unordered_set<string> set;
        string s;
        vector<string> ans;
        for (auto& e : generateParenthesis(n - 1))
        {
            for (int i = 0; i < 2 * n - 1; ++i)
            {
                s = e.substr(0, i) + "()" + e.substr(i, 2 * n - 1);
                set.insert(s);
            }
        }
        for (auto& e : set)
        {
            ans.push_back(e);
        }
        return ans;
    }
};