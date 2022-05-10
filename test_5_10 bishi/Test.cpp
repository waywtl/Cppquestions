#define _CRT_SECURE_NO_WARNINGS 1

//美国节日
#include <iostream>
using namespace std;

bool IsLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int GetMonthDay(int year, int month)
{
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day = arr[month];
    if (IsLeapYear(year) && month == 2)
        day += 1;
    return day;
}

int main()
{
    int year = 0;
    int* day = new int[10000];
    day[2000] = 6;
    for (int i = 2001; i < 10000; ++i)
    {
        if (IsLeapYear(i - 1))
            day[i] = day[i - 1] + 2;
        else
            day[i] = day[i - 1] + 1;
        if (day[i] == 8)
            day[i] = 1;
        if (day[i] == 9)
            day[i] = 2;
    }
    while (cin >> year)
    {
        int date = day[year];
        int day1, day2, day3, day4, day5;
        for (int i = 1; i <= 12; ++i)
        {
            int cnt = 0;
            for (int j = 1; j <= GetMonthDay(year, i); ++j)
            {
                if (i == 1)
                {
                    if (date == 1)
                        ++cnt;
                    if (cnt == 3)
                    {
                        day1 = j;
                        cnt = -5;
                    }
                }
                else if (i == 2)
                {
                    if (date == 1)
                        ++cnt;
                    if (cnt == 3)
                    {
                        day2 = j;
                        cnt = -5;
                    }
                }
                else if (i == 5)
                {
                    if (j >= 25 && j <= 31 && date == 1)
                        day3 = j;
                }
                else if (i == 9)
                {
                    if (date == 1)
                        ++cnt;
                    if (cnt == 1)
                    {
                        day4 = j;
                        cnt = -5;
                    }
                }
                else if (i == 11)
                {
                    if (date == 4)
                        ++cnt;
                    if (cnt == 4)
                    {
                        day5 = j;
                        cnt = -5;
                    }
                }
                ++date;
                if (date == 8)
                    date = 1;
            }
        }
        printf("%d-01-01\n", year);
        printf("%d-01-%02d\n", year, day1);
        printf("%d-02-%02d\n", year, day2);
        printf("%d-05-%02d\n", year, day3);
        printf("%d-07-04\n", year);
        printf("%d-09-%02d\n", year, day4);
        printf("%d-11-%02d\n", year, day5);
        printf("%d-12-25\n", year);
        cout << endl;
    }
    delete[] day;
    return 0;
}

//分解因数
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        printf("%d = ", n);
        for (int i = 2; i <= sqrt(n); ++i)
        {
            while (n != i)
            {
                if (n % i == 0)
                {
                    printf("%d * ", i);
                    n /= i;
                }
                else
                    break;
            }
        }
        printf("%d\n", n);
    }
    return 0;
}