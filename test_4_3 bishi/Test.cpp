#define _CRT_SECURE_NO_WARNINGS 1

//查找组成一个偶数最近的两个素数
#include <iostream>
using namespace std;

bool IsPrimeNumber(int num)
{
    for (int i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 0;
    cin >> n;
    int ret1 = 0;
    int ret2 = 0;
    for (int i = (n / 2); i > 1; --i)
    {
        if (IsPrimeNumber(i))
        {
            if (IsPrimeNumber(n - i))
            {
                ret1 = i;
                ret2 = n - i;
                break;
            }
        }
    }
    cout << ret1 << endl;
    cout << ret2 << endl;
    return 0;
}