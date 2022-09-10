#define _CRT_SECURE_NO_WARNINGS 1

//修剪二叉搜索树
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val < low)
            return trimBST(root->right, low, high);

        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, root->val);
        root->right = trimBST(root->right, root->val, high);
        return root;
    }
};

//检查网格中是否存在有效路径
class Solution {
public:
    int n;
    int m;
    int row;
    int col;
    bool ret = false;

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != 1)
            return;

        if (x >= (n - 1) * 3 + 1 && y >= (m - 1) * 3 + 1)
        {
            ret = true;
            return;
        }

        grid[x][y] = -1;
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        grid[x][y] = 1;
    }

    bool hasValidPath(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();

        row = n * 3;
        col = m * 3;
        vector<vector<int>> _grid(row, vector<int>(col, 0));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int x = i * 3 + 1;
                int y = j * 3 + 1;
                int num = grid[i][j];

                switch (num)
                {
                case 1:
                    _grid[x][y - 1] = 1;
                    _grid[x][y] = 1;
                    _grid[x][y + 1] = 1;
                    break;
                case 2:
                    _grid[x - 1][y] = 1;
                    _grid[x][y] = 1;
                    _grid[x + 1][y] = 1;
                    break;
                case 3:
                    _grid[x][y - 1] = 1;
                    _grid[x][y] = 1;
                    _grid[x + 1][y] = 1;
                    break;
                case 4:
                    _grid[x][y + 1] = 1;
                    _grid[x][y] = 1;
                    _grid[x + 1][y] = 1;
                    break;
                case 5:
                    _grid[x - 1][y] = 1;
                    _grid[x][y] = 1;
                    _grid[x][y - 1] = 1;
                    break;
                case 6:
                    _grid[x - 1][y] = 1;
                    _grid[x][y] = 1;
                    _grid[x][y + 1] = 1;
                    break;
                default:
                    break;
                }
            }
        }

        dfs(_grid, 1, 1);
        return ret;
    }
};

//股票平滑下跌阶段的数目
//方法1：深搜+回溯 O(n2) 不能ac
class Solution {
public:
    long long ans;
    int n;
    bool flag;

    void dfs(vector<int>& prices, int i, int pre)
    {
        if (i == n)
            return;
        for (int j = i; j < n; ++j)
        {
            flag = true;
            if (pre == 0 || pre - prices[j] == 1)
            {
                ++ans;
                dfs(prices, j + 1, prices[j]);
                if (!flag && pre != 0)
                    break;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    long long getDescentPeriods(vector<int>& prices)
    {
        n = prices.size();
        dfs(prices, 0, 0);
        return ans;
    }
};

//方法2：双指针 O(n)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long ans = 0;
        int n = prices.size();
        int i = 0;
        int j = 1;
        long long len = 1;
        while (i < n && j < n)
        {
            if (prices[i] - prices[j] == len)
            {
                ++len;
                ++j;
            }
            else
            {
                ans += len * (len + 1) / 2;
                len = 1;
                i = j;
                j = i + 1;
            }
        }
        ans += len * (len + 1) / 2;
        return ans;
    }
};

//方法3：动态规划 O(n)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long ans = 1;
        int n = prices.size();
        int pre = 1;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i - 1] - prices[i] == 1)
                ++pre;
            else
                pre = 1;

            ans += pre;
        }
        return ans;
    }
};