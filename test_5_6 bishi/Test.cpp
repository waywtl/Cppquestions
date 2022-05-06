#define _CRT_SECURE_NO_WARNINGS 1

//求正数数组的最小不可组成和
//方法1:求出所有可能和
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     *	正数数组中的最小不可组成和
     *	输入：正数数组arr
     *	返回：正数数组中的最小不可组成和
     */
    void GetSum(const vector<int>& arr, int sum, int i, vector<int>& num, unordered_set<int> set)
    {
        if (i != 0 && !set.count(sum))
        {
            num.push_back(sum);
            set.insert(sum);
        }
        for (int j = i; j < arr.size(); ++j)
        {
            GetSum(arr, sum + arr[j], j + 1, num, set);
        }
    }

    int getFirstUnFormedNum(vector<int> arr, int len)
    {
        int sum = 0;
        vector<int> num;
        unordered_set<int> set;
        GetSum(arr, sum, 0, num, set);
        sort(num.begin(), num.end());
        int ret = 0;
        for (int i = 1; i < num.size(); ++i)
        {
            if (num[i] - num[i - 1] > 1)
            {
                ret = num[i - 1] + 1;
                break;
            }
        }
        if (ret == 0)
            ret = num[num.size() - 1] + 1;
        return ret;
    }
};

//方法2：转化为01背包问题
#include <iostream>
#include <vector>
using namespace std;

class Solutions {
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        for (int i = 0; i < len; ++i)
        {
            sum += arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; ++i)
        {
            for (int j = sum; j >= min; --j)
            {
                if (j >= arr[i])
                {
                    dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
                }
            }
        }

        for (int i = min; i <= sum; ++i)
        {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};

//找假币
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        else if (n == 2 || n == 3)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            int cnt = 1;
            while (n > 3)
            {
                if (n % 3 == 0)
                    n /= 3;
                else
                    n = n / 3 + 1;
                ++cnt;
            }
            cout << cnt << endl;
        }

    }
    return 0;
}