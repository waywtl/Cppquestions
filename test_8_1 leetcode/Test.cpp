#define _CRT_SECURE_NO_WARNINGS 1

//二叉树的最近公共祖先
//方法一：存储父节点
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& v)
    {
        if (root == nullptr)
            return false;
        v.push_back(root);
        if (root == node)
            return true;

        if (dfs(root->left, node, v))
            return true;
        if (dfs(root->right, node, v))
            return true;
        v.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;
        dfs(root, p, pv);
        dfs(root, q, qv);
        int i = 0;
        for (; i < pv.size() && i < qv.size(); ++i)
        {
            if (pv[i] != qv[i])
                break;
        }
        return pv[i - 1];
    }
};

//方法二:递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return root;
    }
};

//除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        int left_mul = 1;
        vector<int> ans(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            ans[i] = ans[i + 1] * nums[i + 1];
        }
        for (int i = 1; i < n; ++i)
        {
            left_mul *= nums[i - 1];
            ans[i] = left_mul * ans[i];
        }
        return ans;
    }
};

//滑动窗口最大值
//方法一：用multiset保存当前k个值，窗口右移时，不断把左边的值移除
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {    
         int n = nums.size();
         vector<int> ans;
         multiset<int, greater<int>> s;
         for(int i = 0; i < k; ++i)
             s.insert(nums[i]);
         for(int i = 0; i < n-k; ++i)
         {
             ans.push_back(*s.begin());
             s.erase(s.find(nums[i]));
             s.insert(nums[i+k]);
         }
         ans.push_back(*s.begin());
         return ans;
    }
};

//方法二：优先级队列保存当前k个值，窗口右移时，不断把在堆顶且不在窗口中的值移除
 class Solution {
 public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k)
     {
         int n = nums.size();
         vector<int> ans;
         priority_queue<pair<int, int>> q;
         for(int i = 0; i < k; ++i)
             q.push(make_pair(nums[i], i));

         ans.push_back(q.top().first);
         for(int i = k; i < n; ++i)
         {
             q.push(make_pair(nums[i], i));
             while(q.top().second <= i-k)
                 q.pop();
             ans.push_back(q.top().first);
         }
         return ans;
     }
 };

 //方法三：单调队列
 //队列中保存数组下标，且使下标对应的元素严格递减，若队尾的元素严格小于入队的元素，
 //则不断出队尾的元素，直到队尾元素大于当前元素或队列为空
 //此时队头的元素及为滑动窗口最大值
 //同时也要保证队头元素在窗口中，否则出队
 class Solution {
 public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k)
     {
         int n = nums.size();
         vector<int> ans;
         deque<int> q;
         for (int i = 0; i < k; ++i)
         {
             while (!q.empty() && nums[i] >= nums[q.back()])
                 q.pop_back();
             q.push_back(i);
         }

         ans.push_back(nums[q.front()]);
         for (int i = k; i < n; ++i)
         {
             while (!q.empty() && nums[i] >= nums[q.back()])
                 q.pop_back();
             q.push_back(i);
             while (q.front() <= i - k)
                 q.pop_front();
             ans.push_back(nums[q.front()]);
         }
         return ans;
     }
 };