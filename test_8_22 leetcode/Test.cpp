#define _CRT_SECURE_NO_WARNINGS 1

//路径总和Ⅲ
//方法1：递归  O(n2)
 class Solution {
 public:
     int ans = 0;
     int target = 0;
     long long sum = 0;

     void dfs(TreeNode* root, long long sum)
     {
         if(root == nullptr)
             return;

         sum += root->val;

         if(sum == target)
             ++ans;

         dfs(root->left, sum);
         dfs(root->right, sum);
     }

     int pathSum(TreeNode* root, int targetSum)
     {
         if(root == nullptr)
             return 0;
         target = targetSum;
         dfs(root, 0);
         pathSum(root->left, targetSum);
         pathSum(root->right, targetSum);
         return ans;
     }
 };

 //方法2：前缀和 O(n)
 class Solution {
 public:
     int ans = 0;
     unordered_map<long long, int> m;

     void dfs(TreeNode* root, long long sum, int targetSum)
     {
         if (root == nullptr)
             return;

         sum += root->val;

         if (m.count(sum - targetSum))
             ans += m[sum - targetSum];

         m[sum]++;
         dfs(root->left, sum, targetSum);
         dfs(root->right, sum, targetSum);
         m[sum]--;
     }

     int pathSum(TreeNode* root, int targetSum)
     {
         m[0] = 1;
         dfs(root, 0, targetSum);
         return ans;
     }
 };

//找到字符串中所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int s_len = s.size();
        int p_len = p.size();
        if (s_len < p_len)
            return {};
        vector<int> ans;
        int p_arr[26] = { 0 };
        int s_arr[26] = { 0 };

        for (auto& ch : p)
            ++p_arr[ch - 'a'];

        int i = 0;
        int j = 0;
        while (j < p_len)
        {
            ++s_arr[s[j] - 'a'];
            ++j;
        }

        --j;
        while (j < s_len)
        {
            int flag = 1;
            for (int k = 0; k < 26; ++k)
            {
                if (s_arr[k] != p_arr[k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                ans.push_back(i);
            if (j == s_len - 1)
                break;
            --s_arr[s[i++] - 'a'];
            ++s_arr[s[++j] - 'a'];
        }
        return ans;
    }
};