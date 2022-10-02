#define _CRT_SECURE_NO_WARNINGS 1

//公因子的数目
class Solution {
public:
    int commonFactors(int a, int b)
    {
        int ans = 0;
        while (b)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        for (int i = 1; i <= a; ++i)
        {
            if (a % i == 0)
                ++ans;
        }
        return ans;
    }
};

//沙漏的最大总和
class Solution {
public:
    int maxSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 1; i < m - 1; ++i)
        {
            int sum = 0;
            for (int j = 1; j < n - 1; ++j)
            {
                sum = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

//最小XOR
class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        int ans = 0;
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        if (cnt2 == cnt1)
        {
            ans = num1;
        }
        else if (cnt2 < cnt1)
        {
            int num = 1 << 30;
            while (cnt2)
            {
                if ((num & num1) == num)
                {
                    ans |= num;
                    cnt2--;
                }
                num >>= 1;
            }
        }
        else
        {
            int dif = cnt2 - cnt1;
            int num = 1;
            while (dif)
            {
                if ((num & num1) == 0)
                {
                    ans |= num;
                    dif--;
                }
                num <<= 1;
            }
            ans |= num1;
        }
        return ans;
    }
};