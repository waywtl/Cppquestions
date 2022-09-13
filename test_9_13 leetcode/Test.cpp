#define _CRT_SECURE_NO_WARNINGS 1

//最大交换
class Solution {
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size();
        string cp = s;
        sort(cp.begin(), cp.end(), [](char c1, char c2) {return c1 > c2; });

        char l = 0;
        char b = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cp[i] != s[i])
            {
                l = s[i];
                b = cp[i];
                break;
            }
        }

        if (l == b)
            return num;

        int i = 0;
        int j = n - 1;
        for (; i < n; ++i)
        {
            if (s[i] == l)
                break;
        }

        for (; j >= 0; --j)
        {
            if (s[j] == b)
                break;
        }

        char tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;

        return stoi(s);
    }
};

//被列覆盖的最多行数
class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            int num = 0;
            for (int j = 0; j < m; ++j)
            {
                num *= 2;
                num += mat[i][j];
            }
            v[i] = num;
        }

        int ret = 0;
        for (int i = 1; i < (1 << m); ++i)
        {
            if (__builtin_popcount(i) == cols)
            {
                int cnt = 0;
                for (int j = 0; j < n; ++j)
                {
                    if ((v[j] & i) == v[j])
                        ++cnt;
                }
                ret = max(cnt, ret);
            }
        }
        return ret;
    }
};