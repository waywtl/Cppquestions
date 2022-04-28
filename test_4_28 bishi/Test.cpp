#define _CRT_SECURE_NO_WARNINGS 1

//ºï×Ó·ÖÌÒ
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        else
        {
            long a = pow(5, n) - 4;
            long b = pow(4, n) + n - 4;
            cout << a << " " << b << endl;
        }
    }
    return 0;
}