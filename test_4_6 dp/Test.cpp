#define _CRT_SECURE_NO_WARNINGS 1

//编辑距离
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int row = word1.size();
        int col = word2.size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i <= col; ++i)
            dp[0][i] = i;
        for (int i = 0; i <= row; ++i)
            dp[i][0] = i;

        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[row][col];
    }
};

//不同子序列
//二维
/*class Solution {
public:
    int numDistinct(string s, string t)
    {
        int row = s.size();
        int col = t.size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= row; ++i)
        {
            for(int j = 1; j <= col; ++j)
            {
                dp[i][0] = 1;
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[row][col];
    }
};*/

//一维
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int row = s.size();
        int col = t.size();
        if (row < col)
            return 0;

        vector<int> dp(col + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= row; ++i)
        {
            for (int j = col; j > 0; --j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[col];
    }
};