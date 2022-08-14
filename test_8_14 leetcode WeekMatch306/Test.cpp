#define _CRT_SECURE_NO_WARNINGS 1

//矩阵中的局部最大值
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = 0; j < n - 2; ++j)
            {
                int num = 0;
                for (int k = i; k < i + 3; ++k)
                {
                    for (int l = j; l < j + 3; ++l)
                    {
                        if (grid[k][l] > num)
                            num = grid[k][l];
                    }
                }
                ans[i][j] = num;
            }
        }
        return ans;
    }
};

//边积分最高的节点
class Solution {
public:
    int edgeScore(vector<int>& edges)
    {
        int n = edges.size();
        long long arr[100001] = { 0 };
        for (int i = 0; i < n; ++i)
        {
            arr[edges[i]] += i;
        }

        int ans = 0;
        for (int i = 0; i < 100001; ++i)
        {
            if (arr[i] > arr[ans])
                ans = i;
        }
        return ans;
    }
};

//根据模式串构造最小数字
class Solution {
public:
    string smallestNumber(string s)
    {
        s += 'D';
        int n = s.size();
        string ans(n, 'a');
        char num = '1';
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'I')
            {
                index = i - 1;
                ans[i] = num++;
                while (index >= 0 && ans[index] == 'a')
                    ans[index--] = num++;
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (ans[i] != 'a')
                break;
            ans[i] = num++;
        }
        return ans;
    }
};

//统计特殊整数
class Solution {
public:
    int countSpecialNumbers(int n)
    {
        if (n <= 10)
            return n;
        string s = to_string(n);

        int len = s.size();
        vector<int> dp(len, 0);
        dp[1] = 9;
        int ans = 9;

        //以954516为例
        //dp[i]记录i位数中，没有重复位数的个数
        //计算1 ~ 100000中的个数
        for (int i = 2; i < len; ++i)
        {
            dp[i] = dp[i - 1] * (11 - i);
            ans += dp[i];
        }

        //计算100001 ~ 900000中的个数
        int first = (n / (pow(10, len - 1))) - 1;
        for (int i = 0; i < len - 1; ++i)
        {
            first *= (9 - i);
        }
        ans += first;

        //计算900001 ~ 954516中的个数
        bool book[10] = { false };
        book[s[0] - '0'] = true;
        for (int i = 1; i < len; ++i)
        {
            if (i == len - 1)
            {
                for (int j = 0; j <= s[i] - '0'; ++j)
                {
                    if (!book[j])
                        ++ans;
                }
                break;
            }

            int mul_i = 0;
            for (int j = 0; j < s[i] - '0'; ++j)
            {
                if (!book[j])
                    ++mul_i;
            }

            for (int j = i; j < len - 1; ++j)
            {
                mul_i *= (9 - j);
            }

            ans += mul_i;
            if (book[s[i] - '0'])
                break;
            book[s[i] - '0'] = true;
        }
        return ans;
    }
};