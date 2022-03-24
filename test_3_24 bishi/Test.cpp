#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


//×é¶Ó¾ºÈü
int main()
{
    int n = 0;
    cin >> n;
    int tmp = n * 3;
    vector<int> v;
    v.resize(tmp);
    for (int i = 0; i < tmp; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    tmp = n;
    long long int total = 0;
    for (int i = v.size() - 2; tmp--; i -= 2)
    {
        total += v[i];
    }
    cout << total << endl;
    return 0;
}