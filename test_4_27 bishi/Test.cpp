#define _CRT_SECURE_NO_WARNINGS 1

//不用加减乘除做加法
class Solution {
public:
    int Add(int num1, int num2)
    {
        int ret = 0;
        while (num1 != 0)
        {
            ret = num1 ^ num2;
            num1 = (num1 & num2) << 1;
            num2 = ret;
        }
        return num2;
    }
};

//判断是否能组成三角形
#include <iostream>
using namespace std;

int Triangle(double a, double b, double c)
{
    if (a + b > c)
    {
        if (a + c > b && b + c > a)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int main()
{
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        int ret = Triangle(a, b, c);
        if (ret == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}