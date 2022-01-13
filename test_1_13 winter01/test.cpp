#define _CRT_SECURE_NO_WARNINGS 1
//day 01
//自守数
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int i = 0;
    for (i = 0; i <= n; i++)
    {
        int digit = 1;
        int tmp = i;
        while (tmp)
        {
            if (tmp /= 10)
                digit++;
        }
        int iSquare = i * i;
        tmp = i;
        while (digit)
        {
            if ((iSquare % 10) != (tmp % 10))
            {
                break;
            }
            iSquare /= 10;
            tmp /= 10;
            digit--;
        }
        if (digit == 0)
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}

//质数
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int tmp = i;
        int j = 0;
        for (j = 2; j < tmp; j++)
        {
            if (tmp % j == 0)
                break;
        }
        if (tmp == j)
            count++;
    }
    printf("%d\n", count);
    return 0;
}