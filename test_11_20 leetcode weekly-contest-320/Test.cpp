#define _CRT_SECURE_NO_WARNINGS 1

//�����в�����Ԫ�����Ŀ
// 
//��Ŀ�Ѷ�Easy
//����һ���±�� 0 ��ʼ������������ nums �������ҳ���ͳ������������������Ԫ��(i, j, k) ����Ŀ��
//
//0 <= i < j < k < nums.length
//    nums[i]��nums[j] �� nums[k] ������ͬ ��
//    ���仰˵��nums[i] != nums[j]��nums[i] != nums[k] �� nums[j] != nums[k] ��
//    ������������������Ԫ�����Ŀ��
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

//6242. ��������������ڵ��ѯ ��ʾӢ������ 
//
//��Ŀ�Ѷ�Medium
//����һ�� ���������� �ĸ��ڵ� root ����һ������������ɡ�����Ϊ n ������ queries ��
//
//�����ҳ�һ������Ϊ n �� ��ά ������ answer ������ answer[i] = [mini, maxi] ��
//
//mini ������С�ڵ��� queries[i] �� ���ֵ �����������������ֵ����ʹ�� - 1 ���档
//maxi �����д��ڵ��� queries[i] �� ��Сֵ �����������������ֵ����ʹ�� - 1 ���档
//�������� answer ��
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

//6243. �����׶��������ͺ� ��ʾӢ������
//
//��Ŀ�Ѷ�Medium
//����һ�� n ���ڵ������һ��������ͨ���޻�ͼ����ÿ���ڵ��ʾһ�����У���Ŵ� 0 �� n - 1 ����ǡ���� n - 1 ��·��0 ���׶�������һ����ά�������� roads ������ roads[i] = [ai, bi] ����ʾ���� ai �� bi ֮����һ�� ˫��· ��
//
//ÿ����������һ���������Ƕ�Ҫȥ�׶��μ�һ�����顣
//
//ÿ����������һ����������һ������ seats ��ʾÿ����������λ����Ŀ��
//
//������Ĵ������ѡ��������ڳ��еĳ������߳����������еĳ������ڳ���֮��һ�������ͺ���һ�����͡�
//
//���㷵�ص����׶�������Ҫ���������͡�
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