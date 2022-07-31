//#define _CRT_SECURE_NO_WARNINGS 1
//
//实现Trie(前缀树)
class Trie {
private:
    bool _is_end;
    Trie* next[26];
public:
    Trie()
    {
        _is_end = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word)
    {
        Trie* node = this;
        for (auto& c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie;
            }
            node = node->next[c - 'a'];
        }
        node->_is_end = true;
    }

    bool search(string word)
    {
        Trie* node = this;
        for (auto& c : word)
        {
            node = node->next[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }
        }
        return node->_is_end;
    }

    bool startsWith(string prefix)
    {
        Trie* node = this;
        for (auto& c : prefix)
        {
            node = node->next[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }
        }
        return true;
    }
};

//最大正方形
//方法一：暴力
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> book(n, vector<int>(m, 0));
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    area = max(1, area);
                    book[i][j] = ((j > 0) ? book[i][j - 1] + 1 : 1);
                    int min_len = book[i][j];
                    for (int k = i - 1; k >= 0 && matrix[k][j] == '1'; --k)
                    {
                        int len = i - k + 1;
                        min_len = min(min_len, book[k][j]);
                        if (min_len >= len)
                            area = max(area, len * len);
                        else
                            break;
                    }
                }
            }
        }
        return area;
    }
};

//方法二：动态规划
//以当前点为正方形的右下顶点，边长依赖左，上，左上边长的最小值
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                    {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                }
                area = max(area, dp[i][j] * dp[i][j]);
            }
        }
        return area;
    }
};