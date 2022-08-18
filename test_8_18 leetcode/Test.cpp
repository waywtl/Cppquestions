#define _CRT_SECURE_NO_WARNINGS 1

//零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//打家劫舍Ⅲ
//方法1：暴力+hash
 class Solution {
 public:
     unordered_map<TreeNode*, int> m;
     int rob(TreeNode* root)
     {
         if(root == nullptr)
             return 0;

         //选当前节点
         int money = root->val;
         if(m.find(root) != m.end())
             return m[root];
         if(root->left != nullptr)
             money += rob(root->left->left) + rob(root->left->right);
         if(root->right != nullptr)
             money += rob(root->right->left) + rob(root->right->right);
         //不选当前节点
         int res = max(money, rob(root->left)+rob(root->right));

         m[root] = res;
         return res;
     }
 };

 //方法2：定义状态
 class Solution {
 public:
     pair<int, int> solve(TreeNode* root)
     {
         if (root == nullptr)
             return { 0, 0 };

         auto l = solve(root->left);
         auto r = solve(root->right);

         return { max(l.first, l.second) + max(r.first, r.second), l.first + r.first + root->val };
     }

     int rob(TreeNode* root)
     {
         pair<int, int> p = solve(root);
         return max(p.first, p.second);
     }
 };