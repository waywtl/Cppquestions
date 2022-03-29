#define _CRT_SECURE_NO_WARNINGS 1

//两种排序方法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string IsDictionarySort(vector<string>& vs)
{
    string ret("");
    for (int i = 0; i < vs.size() - 1; ++i)
    {
        if (vs[i + 1] < vs[i])
        {
            return ret;
        }
    }
    ret = "lexicographically";
    return ret;
}

string IsLengthsSort(vector<string>& vs)
{
    string ret("");
    for (int i = 0; i < vs.size() - 1; ++i)
    {
        if (vs[i + 1].size() < vs[i].size())
        {
            return ret;
        }
    }
    ret = "lengths";
    return ret;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<string> vs;
    vs.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vs[i];
    }
    string ret1 = IsDictionarySort(vs);
    string ret2 = IsLengthsSort(vs);
    if (ret1 == "lexicographically" && ret2 == "lengths")
        cout << "both" << endl;
    else if (ret1 == "lexicographically" && ret2 == "")
        cout << ret1 << endl;
    else if (ret1 == "" && ret2 == "lengths")
        cout << ret2 << endl;
    else
        cout << "none" << endl;
    return 0;
}


//最小公倍数
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    int mul = a * b;
    int num = 1;
    while (num != 0)
    {
        num = a > b ? a % b : b % a;
        if (num != 0)
        {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
    }
    num = min(a, b);
    cout << mul / num << endl;
    return 0;
}