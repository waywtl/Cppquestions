#define _CRT_SECURE_NO_WARNINGS 1

//数组中不等三元组的数目
// 
//题目难度Easy
//给你一个下标从 0 开始的正整数数组 nums 。请你找出并统计满足下述条件的三元组(i, j, k) 的数目：
//
//0 <= i < j < k < nums.length
//    nums[i]、nums[j] 和 nums[k] 两两不同 。
//    换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。
//    返回满足上述条件三元组的数目。
class Solution {
public:
    int unequalTriplets(vector<int>& nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                        ++ans;
                }
            }
        }
        return ans;
    }
};

//6242. 二叉搜索树最近节点查询 显示英文描述 
//
//题目难度Medium
//给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。
//
//请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：
//
//mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 - 1 代替。
//maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 - 1 代替。
//返回数组 answer 。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> nums;
    int n;

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        nums.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int low(vector<int>& nums, int target)
    {
        int i = 0;
        int j = n - 1;
        int mid = 0;
        while (i < j)
        {
            mid = (i + j + 1) / 2;
            if (nums[mid] <= target)
                i = mid;
            else
                j = mid - 1;
        }

        if (nums[i] > target)
            return -1;
        return nums[i];
    }

    int up(vector<int>& nums, int target)
    {
        int i = 0;
        int j = n - 1;
        int mid = 0;
        while (i < j)
        {
            mid = (i + j) / 2;
            if (nums[mid] >= target)
                j = mid;
            else
                i = mid + 1;
        }

        if (nums[j] < target)
            return -1;
        return nums[j];
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
    {
        vector<vector<int>> ans;
        dfs(root);
        n = nums.size();
        sort(nums.begin(), nums.end());

        for (auto& num : queries)
        {
            int x = low(nums, num);
            int y = up(nums, num);

            ans.push_back({ x, y });
        }
        return ans;
    }
};

//6243. 到达首都的最少油耗 显示英文描述
//
//题目难度Medium
//给你一棵 n 个节点的树（一个无向、连通、无环图），每个节点表示一个城市，编号从 0 到 n - 1 ，且恰好有 n - 1 条路。0 是首都。给你一个二维整数数组 roads ，其中 roads[i] = [ai, bi] ，表示城市 ai 和 bi 之间有一条 双向路 。
//
//每个城市里有一个代表，他们都要去首都参加一个会议。
//
//每座城市里有一辆车。给你一个整数 seats 表示每辆车里面座位的数目。
//
//城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车。相邻城市之间一辆车的油耗是一升汽油。
//
//请你返回到达首都最少需要多少升汽油。
class Solution {
public:
    vector<vector<int>> g;
    long long ans;
    int seat;

    int dfs(int x, int fa)
    {
        int size = 1;
        for (auto& y : g[x])
        {
            if (y != fa)
                size += dfs(y, x);
        }

        if (x)
        {
            ans += ((size + seat - 1) / seat);
        }
        return size;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats)
    {
        ans = 0;
        seat = seats;
        int n = roads.size();
        g.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }

        dfs(0, -1);

        return ans;
    }
};