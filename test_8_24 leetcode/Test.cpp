#define _CRT_SECURE_NO_WARNINGS 1

//把二叉搜索树转换为累加树
//方法1
class Solution {
public:
    int
        void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        nums[10000 + root->val] = root->val;
        dfs(root->left);
        dfs(root->right);
    }

    void solve(TreeNode* root)
    {
        if (root == nullptr)
            return;
        root->val = nums[10000 + root->val];
        solve(root->left);
        solve(root->right);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        dfs(root);
        for (int i = 19999; i >= 0; --i)
            nums[i] += nums[i + 1];
        solve(root);
        return root;
    }
};

//方法2
class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }

    TreeNode* convertBST(TreeNode* root)
    {
        dfs(root);
        return root;
    }
};

//二叉树的直径
class Solution {
public:
    int ans = 0;
    int depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return ans;
    }
};