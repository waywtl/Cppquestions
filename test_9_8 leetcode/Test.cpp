#define _CRT_SECURE_NO_WARNINGS 1

//优美的排列Ⅱ
class Solution {
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        for (int i = 1; i < n - k; ++i)
            ans.push_back(i);

        for (int i = n - k, j = n; i <= j; ++i, --j)
        {
            if (i == j)
            {
                ans.push_back(i);
                break;
            }
            ans.push_back(i);
            ans.push_back(j);
        }

        return ans;
    }
};

//分割回文串
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> ans;
    vector<vector<bool>> dp;
    int n;

    void dfs(const string& s, int i)
    {
        if (i == n)
        {
            ret.push_back(ans);
            return;
        }

        for (int j = i; j < n; ++j)
        {
            if (dp[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        dp.assign(n, vector<bool>(n, true));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
        }

        dfs(s, 0);
        return ret;
    }
};

//二叉树的最小深度
class Solution {
public:
    int len = 0;
    int ans = INT_MAX;

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;

        ++len;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans = min(ans, len);
            --len;
            return;
        }

        dfs(root->left);
        dfs(root->right);
        --len;
    }

    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        dfs(root);
        return ans;
    }
};