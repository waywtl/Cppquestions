#define _CRT_SECURE_NO_WARNINGS 1

//左右最值最大差
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n)
    {
        vector<int> left_max(n);
        left_max[0] = A[0];
        vector<int> right_max(n);
        right_max[n - 1] = INT_MIN;

        for (int i = 1; i < n; ++i)
        {
            left_max[i] = max(A[i], left_max[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i)
        {
            right_max[i] = max(A[i + 1], right_max[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            ans = max(ans, abs(left_max[i] - right_max[i]));
        }
        return ans;
    }
};

//顺时针打印矩阵
class Printer {
public:
    int i = 0;
    int j = 0;
    int k = 0;
    void Right(vector<vector<int>>& mat, vector<int>& ans, vector<vector<bool>>& book)
    {
        if (i != 0)
            ++k;
        int n = mat.size();
        int m = mat[0].size();
        while (j < n && k < m && book[j][k] == false)
        {
            book[j][k] = true;
            ans[i++] = mat[j][k];
            ++k;
        }
        --k;
    }
    void Down(vector<vector<int>>& mat, vector<int>& ans, vector<vector<bool>>& book)
    {
        ++j;
        int n = mat.size();
        int m = mat[0].size();
        while (j < n && k < m && book[j][k] == false)
        {
            book[j][k] = true;
            ans[i++] = mat[j][k];
            ++j;
        }
        --j;
    }
    void Left(vector<vector<int>>& mat, vector<int>& ans, vector<vector<bool>>& book)
    {
        --k;
        int n = mat.size();
        int m = mat[0].size();
        while (j >= 0 && k >= 0 && book[j][k] == false)
        {
            book[j][k] = true;
            ans[i++] = mat[j][k];
            --k;
        }
        ++k;
    }
    void Up(vector<vector<int>>& mat, vector<int>& ans, vector<vector<bool>>& book)
    {
        --j;
        int n = mat.size();
        int m = mat[0].size();
        while (j >= 0 && k >= 0 && book[j][k] == false)
        {
            book[j][k] = true;
            ans[i++] = mat[j][k];
            --j;
        }
        ++j;
    }
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m)
    {
        vector<int> ans(n * m, 0);
        vector<vector<bool>> book(n, vector<bool>(m, false));
        while (i < n * m)
        {
            Right(mat, ans, book);
            Down(mat, ans, book);
            Left(mat, ans, book);
            Up(mat, ans, book);
        }
        return ans;
    }
};