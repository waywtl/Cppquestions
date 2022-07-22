#define _CRT_SECURE_NO_WARNINGS 1

//子集
class Solution {
public:
    void Helper(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int n, int i)
    {
        ans.push_back(v);
        if (i == n)
            return;
        for (; i < n; ++i)
        {
            v.push_back(nums[i]);
            Helper(ans, v, nums, n, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        Helper(ans, v, nums, nums.size(), 0);
        return ans;
    }
};

//单词搜索
class Solution {
public:
    bool dfs(vector<vector<int>>& book, vector<vector<char>>& board, int n, int m, int i, int j, string& word, int index)
    {
        if (i >= n || j >= m || i < 0 || j < 0 || book[i][j] == 1 || board[i][j] != word[index])
            return false;
        book[i][j] = 1;

        if (index + 1 == word.size())
            return true;

        if (dfs(book, board, n, m, i - 1, j, word, index + 1) ||
            dfs(book, board, n, m, i, j + 1, word, index + 1) ||
            dfs(book, board, n, m, i + 1, j, word, index + 1) ||
            dfs(book, board, n, m, i, j - 1, word, index + 1))
            return true;

        book[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> book(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(book, board, n, m, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

//柱状图中最大的矩形
//方法1：暴力搜索 O(n2) 不能ac
 class Solution {
 public:
     int largestRectangleArea(vector<int>& heights)
     {
         int n = heights.size();
         int ans = 0;
         for(int i = 0; i < n; ++i)
         {
             int min_num = heights[i];
             int area = heights[i];
             for(int j = i+1; j < n; ++j)
             {
                 int gap = j - i + 1;
                 min_num = min(heights[j], min_num);
                 area = max(area, gap * min_num);
             }
             ans = max(ans, area);
         }
         return ans;
     }
 };

 //方法2: 单调栈
 class Solution {
 public:
     int largestRectangleArea(vector<int>& heights)
     {
         int n = heights.size();
         stack<int> st;
         int ans = 0;
         for (int i = 0; i < n; ++i)
         {
             while (!st.empty() && heights[st.top()] > heights[i])
             {
                 int height = heights[st.top()];
                 st.pop();
                 int weight = i;
                 if (!st.empty())
                     weight = i - st.top() - 1;
                 ans = max(ans, height * weight);
             }
             st.push(i);
         }

         while (!st.empty())
         {
             int height = heights[st.top()];
             st.pop();
             int weight = n;
             if (!st.empty())
                 weight = n - st.top() - 1;
             ans = max(ans, height * weight);
         }
         return ans;
     }
 };