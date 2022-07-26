#define _CRT_SECURE_NO_WARNINGS 1

//二叉树展开为链表
class Solution {
public:
    void flatten(TreeNode* root)
    {
        if (root == nullptr)
            return;
        flatten(root->left);
        if (root->left != nullptr)
        {
            TreeNode* r = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* tail = root->right;
            while (tail->right)
                tail = tail->right;
            tail->right = r;
        }
        flatten(root->right);
    }
};

//买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int cost = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
        }
        return profit;
    }
};