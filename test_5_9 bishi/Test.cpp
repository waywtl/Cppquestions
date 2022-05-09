#define _CRT_SECURE_NO_WARNINGS 1

//ÌÔ±¦Íøµê
#include <iostream>
using namespace std;

int GetMonthDay(int year, int month)
{
    int arr[13] = { 0,62,28,31,60,31,60,31,62,60,62,30,62 };
    int day = arr[month];
    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
        day += 1;
    return day;
}

bool IsPrimeNum(int n)
{
    if (n == 1 || n == 4 || n == 6 || n == 8 || n == 9
        || n == 10 || n == 12)
        return false;
    else
        return true;
}

int main()
{
    int year1, month1, day1, year2, month2, day2;
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int money = 0;
        if (year1 == year2 && month1 == month2)
        {
            money += (day2 - day1 + 1);
            if (!IsPrimeNum(month1))
                money *= 2;
            cout << money << endl;
        }
        else
        {
            if (!IsPrimeNum(month1))
            {
                money += (GetMonthDay(year1, month1) / 2) - day1 + 1;
                money *= 2;
            }
            else
                money += GetMonthDay(year1, month1) - day1 + 1;
            month1 += 1;
            if (month1 == 13)
            {
                year1 += 1;
                month1 = 1;
            }
            while (year1 != year2 || month1 != month2)
            {
                money += GetMonthDay(year1, month1++);
                if (month1 == 13)
                {
                    year1 += 1;
                    month1 = 1;
                }
            }
            if (!IsPrimeNum(month2))
                money += (day2 * 2);
            else
                money += day2;
            cout << money << endl;
        }
    }
    return 0;
}

//ì³²¨ÄÇÆõ·ïÎ²
#include <iostream>
using namespace std;

int main()
{
    int dp[100001] = { 0 };
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 100001; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    int n = 0;
    while (cin >> n)
    {
        if (n < 29)
            printf("%d\n", dp[n]);
        else
            printf("%06d\n", dp[n]);
    }
    return 0;
}