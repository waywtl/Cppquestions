#define _CRT_SECURE_NO_WARNINGS 1

//三角矩阵最小路径和
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> dp(triangle);
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int lastRow = dp.size() - 1;
        int minNum = dp[lastRow][0];
        for (int i = 0; i < dp[lastRow].size(); ++i)
        {
            minNum = min(minNum, dp[lastRow][i]);
        }
        return minNum;
    }
};

//不同路径数
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

//有障碍物的不同路径数
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (i == 0)
                {
                    if (j != 0 && obstacleGrid[i][j] != 1)
                        dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0)
                {
                    if (obstacleGrid[i][j] != 1)
                        dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    if (obstacleGrid[i][j] != 1)
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};