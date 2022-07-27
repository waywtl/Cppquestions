#define _CRT_SECURE_NO_WARNINGS 1

//二叉树中的最大路径和
class Solution {
public:
    int max_sum = INT_MIN;
    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left_max = max(0, dfs(root->left));
        int right_max = max(0, dfs(root->right));

        int cur_max = left_max + root->val + right_max;
        max_sum = max(max_sum, cur_max);

        return root->val + max(left_max, right_max);
    }

    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return max_sum;
    }
};

//最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        set<int> s;
        for (int& x : nums)
            s.insert(x);

        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;

        int ans = 0;
        auto iter = s.begin();
        int pre = *iter;
        auto cur = ++iter;
        while (cur != s.end())
        {
            int len = 1;
            while (*cur - pre <= 1 && cur != s.end())
            {
                ++len;
                pre = *cur;
                ++cur;
            }
            if (cur != s.end())
            {
                pre = *cur;
                ++cur;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};