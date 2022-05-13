#define _CRT_SECURE_NO_WARNINGS 1

//年会抽奖
#include <iostream>
using namespace std;

int main()
{
    float allwrong[21] = { 0,0,1 };
    float sum[21] = { 0,1,2 };
    for (int i = 3; i < 21; ++i)
    {
        allwrong[i] = (i - 1) * (allwrong[i - 1] + allwrong[i - 2]);
        sum[i] = i * sum[i - 1];
    }
    int n = 0;
    while (cin >> n)
    {
        printf("%.2f%%\n", 100 * allwrong[n] / sum[n]);
    }
    return 0;
}

//抄送列表
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool IsExist(string& s1, string& s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    int i = 0;
    int j = 0;
    unordered_set<string> set;
    while (i < len1)
    {
        if (s1[i] == '"')
        {
            ++i;
            j = i;
            while (j < len1 && s1[j] != '"')
                ++j;
            set.insert(s1.substr(i, j - i));
            i = j + 2;
        }
        else
        {
            j = i;
            while (j < len1 && s1[j] != ',')
                ++j;
            set.insert(s1.substr(i, j - i));
            i = j + 1;
        }
    }
    return set.count(s2);
}

int main()
{
    string s1, s2;
    while (getline(getline(cin, s1), s2))
    {
        if (IsExist(s1, s2))
            cout << "Ignore" << endl;
        else
            cout << "Important!" << endl;
    }
    return 0;
}