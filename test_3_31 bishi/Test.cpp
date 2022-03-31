#define _CRT_SECURE_NO_WARNINGS 1

//密码强度等级
#include <iostream>
#include <string>
using namespace std;

string LevelOfPasswordStrength(string& str)
{
    string ret;
    int passwordLength = str.size();
    int numCount = 0;
    int alphaA = 0;
    int alphaa = 0;
    int symbolCount = 0;
    int reward = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
            ++numCount;
        else if (isalpha(str[i]))
        {
            if (islower(str[i]))
                ++alphaa;
            else
                ++alphaA;
        }
        else if (ispunct(str[i]))
            ++symbolCount;
    }

    int mark = 0;
    if (passwordLength <= 4)
        mark += 5;
    else if (passwordLength <= 7)
        mark += 10;
    else
        mark += 25;

    if (alphaA + alphaa != 0)
    {
        if (alphaA == 0 || alphaa == 0)
            mark += 10;
        else
            mark += 20;
    }

    if (numCount != 0)
    {
        if (numCount == 1)
            mark += 10;
        else
            mark += 20;
    }

    if (symbolCount != 0)
    {
        if (symbolCount == 1)
            mark += 10;
        else
            mark += 25;
    }

    if (alphaA != 0 && alphaa != 0 && numCount != 0 && symbolCount != 0)
        mark += 5;
    else if (alphaA + alphaa != 0 && numCount != 0 && symbolCount != 0)
        mark += 3;
    else if (numCount != 0 && symbolCount != 0)
        mark += 2;

    if (mark >= 90)
        ret = "VERY_SECURE";
    else if (mark >= 80)
        ret = "SECURE";
    else if (mark >= 70)
        ret = "VERY_STRONG";
    else if (mark >= 60)
        ret = "STRONG";
    else if (mark >= 50)
        ret = "AVERAGE";
    else if (mark >= 25)
        ret = "WEAK";
    else if (mark >= 0)
        ret = "VERY_WEAK";

    return ret;
}

int main()
{
    string str;
    cin >> str;
    string ret = LevelOfPasswordStrength(str);
    cout << ret << endl;
    return 0;
}