#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

//数组中只出现一次的数字
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
    {
        int num = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            num ^= data[i];
        }
        int moveCnt = 0;
        while ((num & 1) == 0)
        {
            num >>= 1;
            moveCnt++;
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (((data[i] >> moveCnt) & 1) == 0)
            {
                *num1 ^= data[i];
            }
            else
            {
                *num2 ^= data[i];
            }
        }
    }
};


//和为sum的连续正数序列,滑动窗口
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        vector<vector<int>> vv;
        if (sum == 0)
        {
            return vv;
        }
        int start = 1;
        int end = 2;
        while (start < end)
        {
            int num = (start + end) * (end - start + 1) / 2;
            if (num == sum)
            {
                vector<int> v;
                for (int i = start; i <= end; ++i)
                {
                    v.push_back(i);
                }
                vv.push_back(v);
                start++;
            }
            else if (num > sum)
            {
                start++;
            }
            else
            {
                end++;
            }
        }
        return vv;
    }
};

//左旋字符串
class Solution {
public:
    string LeftRotateString(string str, int n)
    {
        if (str.size() == 0)
            return str;
        int reln = n % str.size();
        /*while(reln--)
        {
            char tmp = str.front();
            str.erase(0, 1);
            str.push_back(tmp);
        }*/
        string tmp(str, 0, reln);
        str.erase(0, reln);
        str += tmp;
        return str;
    }
};