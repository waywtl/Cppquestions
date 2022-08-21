#define _CRT_SECURE_NO_WARNINGS 1

//赢得比赛需要的最少训练时长
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int hours = 0;
        int n = energy.size();
        for (int i = 0; i < n; ++i)
        {
            if (initialEnergy > energy[i])
                initialEnergy -= energy[i];
            else if (initialEnergy == energy[i])
            {
                initialEnergy = 1;
                hours += 1;
            }
            else
            {
                int diff = energy[i] - initialEnergy;
                initialEnergy = 1;
                hours += (diff + 1);
            }

            if (initialExperience > experience[i])
                initialExperience += experience[i];
            else if (initialExperience == experience[i])
            {
                hours += 1;
                initialExperience = 2 * experience[i] + 1;
            }
            else
            {
                int diff = experience[i] - initialExperience;
                initialExperience = (2 * experience[i] + 1);
                hours += (diff + 1);
            }
        }
        return hours;
    }
};

//最大回文数字
class Solution {
public:
    string largestPalindromic(string num)
    {
        int arr[10] = { 0 };
        for (auto& ch : num)
        {
            arr[ch - '0']++;
        }
        string ans;
        int x = -1;
        for (int i = 9; i >= 0; --i)
        {
            if (arr[i] > 1)
            {
                if (ans.size() == 0 && i == 0)
                    continue;
                int cnt = arr[i] / 2;
                while (cnt--)
                {
                    ans += (i + '0');
                }
            }
        }
        string s = ans;
        reverse(s.begin(), s.end());
        for (int i = 9; i >= 0; --i)
        {
            if (arr[i] % 2 != 0)
            {
                ans += (i + '0');
                break;
            }
        }
        ans += s;
        if (ans.size() == 0)
            return "0";
        return ans;
    }
};

//感染二叉树需要的总时间
class Solution {
public:
    queue<TreeNode*> q;
    unordered_map<int, int> mi;
    unordered_map<TreeNode*, TreeNode*> mt;
    int begin = 0;
    int time = 0;

    void solve(TreeNode* root)
    {
        if (root == nullptr)
            return;
        if (mt[root] && mi[mt[root]->val] != 1)
        {
            mi[mt[root]->val] = 1;
            q.push(mt[root]);
        }
        if (root->left && mi[root->left->val] != 1)
        {
            mi[root->left->val] = 1;
            q.push(root->left);
        }
        if (root->right && mi[root->right->val] != 1)
        {
            mi[root->right->val] = 1;
            q.push(root->right);
        }
    }

    void dfs(TreeNode* root, TreeNode* parent)
    {
        if (root == nullptr)
            return;
        if (root->val == begin)
        {
            mi[root->val] = 1;
            q.push(root);
        }
        mt[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }

    int amountOfTime(TreeNode* root, int start)
    {
        begin = start;
        dfs(root, nullptr);

        while (!q.empty())
        {
            ++time;
            int cnt = q.size();
            while (cnt--)
            {
                TreeNode* node = q.front();
                q.pop();
                solve(node);
            }
        }
        return time;
    }
};

//找出数组的第K大和
class Solution {
public:
    long long kSum(vector<int>& nums, int k)
    {
        priority_queue<pair<long long, int>> q;
        long long sum = 0;
        int n = nums.size();
        for (auto& x : nums)
        {
            if (x >= 0)
                sum += x;
            else
                x = -x;
        }
        sort(nums.begin(), nums.end());
        q.push({ sum, 0 });

        while (--k)
        {
            long long cur_sum = q.top().first;
            int i = q.top().second;
            q.pop();
            if (i < n)
            {
                q.push({ cur_sum - nums[i], i + 1 });
                if (i != 0)
                    q.push({ cur_sum - nums[i] + nums[i - 1], i + 1 });
            }
        }
        return q.top().first;
    }
};