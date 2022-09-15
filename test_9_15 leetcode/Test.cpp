#define _CRT_SECURE_NO_WARNINGS 1

//灯泡开关
class Solution {
public:
    int bulbSwitch(int n)
    {
        int ans = 0;
        int i = 1;
        while (i * i <= n)
        {
            ++ans;
            ++i;
        }

        return ans;

        //判断在一个数之前（包含这个数）的完全平方数的个数
        //return sqrt(n+0.5);
    }
};

//灯泡开关Ⅱ
class Solution {
public:
    int flipLights(int n, int presses)
    {
        if (presses == 0)
            return 1;

        if (n == 1)
            return 2;
        else if (n == 2)
            return presses == 1 ? 3 : 4;
        else
            return presses == 1 ? 4 : (presses == 2 ? 7 : 8);
    }
};