#define _CRT_SECURE_NO_WARNINGS 1

//�������������������
//����һ���洢���ڵ�
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

//������:�ݹ�
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

//��������������ĳ˻�
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

//�����������ֵ
//����һ����multiset���浱ǰk��ֵ����������ʱ�����ϰ���ߵ�ֵ�Ƴ�
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

//�����������ȼ����б��浱ǰk��ֵ����������ʱ�����ϰ��ڶѶ��Ҳ��ڴ����е�ֵ�Ƴ�
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

 //����������������
 //�����б��������±꣬��ʹ�±��Ӧ��Ԫ���ϸ�ݼ�������β��Ԫ���ϸ�С����ӵ�Ԫ�أ�
 //�򲻶ϳ���β��Ԫ�أ�ֱ����βԪ�ش��ڵ�ǰԪ�ػ����Ϊ��
 //��ʱ��ͷ��Ԫ�ؼ�Ϊ�����������ֵ
 //ͬʱҲҪ��֤��ͷԪ���ڴ����У��������
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