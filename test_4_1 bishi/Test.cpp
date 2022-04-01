//最近公共祖先
#include <iostream>
#include <algorithm>
using namespace std;

class LCA {
public:
    int getLCA(int a, int b)
    {
        int maxNum = a;
        int minNum = b;
        if (a < b)
            swap(maxNum, minNum);
        if (minNum == 1)
            return 1;
        while (1)
        {
            int tmp = maxNum;
            while (minNum != tmp && tmp != 1)
            {
                tmp /= 2;
            }
            if (minNum == tmp)
                break;
            if (minNum != 1)
                minNum /= 2;
        }
        int ret = minNum;
        return ret;
    }
};

//最大连续1的个数
//方法一：O(n)
/*#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int cnt = 0;
    int tmp = n;
    int maxCnt = 0;
    while(tmp != 0)
    {
        if((tmp & 1) == 1)
            ++cnt;
        else
            cnt = 0;
        tmp >>= 1;
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << endl;
    return 0;
}*/

//方法二： O(logn)
#include<iostream>
using namespace std;
int main()
{
    int byte;
    cin >> byte;
    int k = 0;
    while (byte != 0)
    {
        byte = byte & (byte >> 1);
        ++k;
    }
    cout << k << endl;
    return 0;
}