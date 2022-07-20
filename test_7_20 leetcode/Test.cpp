#define _CRT_SECURE_NO_WARNINGS 1

//全排列
 class Solution {
 public:
     void dfs(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int i, int n)
     {
         if(i == n)
         {
             ans.push_back(v);
             return;
         }
         for(int j = i; j < n; ++j)
         {
             v.push_back(nums[j]);
             swap(nums[i], nums[j]);
             dfs(ans, v, nums, i+1, n);
             swap(nums[i], nums[j]);
             v.pop_back();
         }
     }

     vector<vector<int>> permute(vector<int>& nums)
     {
         vector<vector<int>> ans;
         vector<int> v;
         dfs(ans, v, nums, 0, nums.size());
         return ans;
     }
 };

 //旋转图像
 class Solution {
 public:
     void rotate(vector<vector<int>>& matrix)
     {
         int n = matrix.size();
         //先沿对角线
         for (int i = 0; i < n; ++i)
         {
             for (int j = i + 1; j < n; ++j)
                 swap(matrix[i][j], matrix[j][i]);
         }

         //再沿中线
         for (int i = 0; i < n; ++i)
         {
             for (int j = 0; j < n / 2; ++j)
                 swap(matrix[i][j], matrix[i][n - j - 1]);
         }
     }
 };

 //字母异位词分组
 class Solution {
 public:
     vector<vector<string>> groupAnagrams(vector<string>& strs)
     {
         vector<vector<string>> ans;
         unordered_map<string, vector<string>> m;
         for (string& s : strs)
         {
             string tmp = s;
             sort(tmp.begin(), tmp.end());
             m[tmp].push_back(s);
         }

         for (auto e : m)
         {
             ans.push_back(e.second);
         }
         return ans;

     }
 };