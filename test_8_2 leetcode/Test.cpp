#define _CRT_SECURE_NO_WARNINGS 1

//搜索二维矩阵Ⅱ
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i >= 0 && j >= 0 && i < m && j < n)
        {
            int num = matrix[i][j];
            if (num > target)
                --j;
            else if (num < target)
                ++i;
            else
                return true;
        }
        return false;
    }
};

//完全平方数
class Solution {
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
        {
            int cnt = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
            {
                cnt = min(cnt, dp[i - j * j]);
            }
            dp[i] = cnt + 1;
        }
        return dp[n];
    }
};

//移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (nums[j] != 0)
                nums[i++] = nums[j++];
            else
                ++j;
        }
        while (i < n)
            nums[i++] = 0;
    }
};