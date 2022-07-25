#define _CRT_SECURE_NO_WARNINGS 1

//不同的二叉搜索树
class Solution {
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] += (dp[j] * dp[i - 1 - j]);
            }
        }
        return dp[n];
    }
};

//验证二叉搜索树
class Solution {
public:
    long long pre = LONG_MIN;

    bool Helper(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        bool left_bool = Helper(root->left);
        if (pre >= root->val)
            return false;
        pre = root->val;
        bool right_bool = Helper(root->right);

        return left_bool && right_bool;
    }

    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        return Helper(root);
    }
};