#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

//杨辉三角的变形
//80%
int main()
{
    int n = 0;
    cin >> n;
    int i = 2;
    vector<int> prevV;
    prevV.push_back(1);
    while(i <= n)
    {
        int j = 0;
        int cnt = 2*i - 1;
        vector<int> curV;
        curV.resize(cnt, 0);
        while(j < cnt)
        {
            int left = j-2 >= 0 ? prevV[j-2] : 0;
            int mid = (j-1 >=0 && j-1 < prevV.size()) ? prevV[j-1] : 0;
            int right = j < prevV.size() ? prevV[j] : 0;
            curV[j] = left + mid + right;
            ++j;
        }
        prevV = curV;
        ++i;
    }
    for(int i = 0; i < prevV.size(); ++i)
    {
        if(prevV[i] % 2 == 0)
        {
            cout << i+1 << endl;
            break;
        }
    }
    if(i == prevV.size())
        cout << -1 << endl;
    return 0;
}

//ac
int main()
{
    int n = 0;
    cin >> n;
    if (n <= 2)
        cout << -1 << endl;
    else if ((n % 2) == 1)
        cout << 2 << endl;
    else if (n % 4 == 0)
        cout << 3 << endl;
    else
        cout << 4 << endl;
    return 0;
}