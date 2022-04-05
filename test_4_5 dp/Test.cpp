#define _CRT_SECURE_NO_WARNINGS 1

//背包问题
class Solution {
public:
    int backPackII(int m, vector<int>& A, vector<int>& V)
    {
        if (m == 0 || A.empty() || V.empty())
            return 0;
        int N = A.size();
        int M = m + 1;
        vector<int> ret(M, 0);
        for (int i = 0; i < N; ++i)
        {
            for (int j = M - 1; j > 0; --j)
            {
                if(A[i] <= j)
                {
                    ret[j] = max(ret[j], ret[j - A[i]] + V[i]);
                }
            }
        }
        return ret[m];
    }
};

//分割回文串
class Solution {
public:
    //mat[i][j] 表示字符串s从下标i到下标j的区间是否回文
    vector<vector<bool>> GetMat(const string& s)
    {
        int len = s.size();
        vector<vector<bool>> mat(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i; j < len; ++j)
            {
                if (i == j)
                    mat[i][j] = true;
                else if (j == i + 1)
                    mat[i][j] = (s[i] == s[j]);
                else
                    mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
            }
        }
        return mat;
    }

    int minCut(string s)
    {
        //初始化dp数组，以每组一个字符，最大化初始dp
        int len = s.size();
        vector<int> dp(len + 1, 0);
        for (int i = 0; i <= len; ++i)
        {
            dp[i] = i - 1;
        }

        //获取mat
        vector<vector<bool>> mat = GetMat(s);

        //得到切割最小值
        for (int i = 1; i <= len; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (mat[j][i - 1])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[len];
    }
};