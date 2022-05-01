#define _CRT_SECURE_NO_WARNINGS 1

//组合总和
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ret, vector<int>& v, int sum, int i, int& flag)
    {
        if (sum > target)
        {
            flag = 1;
            return;
        }
        else if (sum == target)
        {
            ret.push_back(v);
            return;
        }
        for (int j = i; j < candidates.size(); ++j)
        {
            v.push_back(candidates[j]);
            dfs(candidates, target, ret, v, sum + candidates[j], j, flag);
            v.pop_back();
            if (flag == 1)
            {
                flag = 0;
                break;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> v;
        int sum = 0;
        int flag = 0;
        dfs(candidates, target, ret, v, sum, 0, flag);
        return ret;
    }
};

//活字印刷
//方法1：set去重
class Solution {
public:
    void dfs(string& tiles, string s, unordered_set<string>& allRet, vector<int>& book)
    {
        if(!s.empty())
        {
            allRet.insert(s);
        }
        for(int i = 0; i < tiles.size(); ++i)
        {
            if(book[i] == 0)
            {
                book[i] = 1;
                dfs(tiles, s+tiles[i], allRet, book);
                book[i] = 0;
            }
        }
    }

    int numTilePossibilities(string tiles)
    {
        if(tiles.size() == 0)
            return 0;
        unordered_set<string> allRet;
        vector<int> book(tiles.size(), 0);
        dfs(tiles, "", allRet, book);
        return allRet.size();
    }
};

//方法2：排序去重
class Solution {
public:
    int cnt = 0;
    void dfs(string& tiles, vector<int>& book)
    {
        for (int i = 0; i < tiles.size(); ++i)
        {
            if (i > 0 && tiles[i - 1] == tiles[i] && book[i - 1] == 0)
                continue;
            if (book[i] == 0)
            {
                book[i] = 1;
                ++cnt;
                dfs(tiles, book);
                book[i] = 0;
            }
        }
    }

    int numTilePossibilities(string tiles)
    {
        if (tiles.size() == 0)
            return 0;
        sort(tiles.begin(), tiles.end());
        vector<int> book(tiles.size(), 0);
        dfs(tiles, book);
        return cnt;
    }
};

//N皇后
class Solution {
public:
    bool isVaildPos(vector<string>& vs, int row, int col, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (vs[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (vs[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (vs[i][j] == 'Q')
                return false;
        }
        for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j)
        {
            if (vs[i][j] == 'Q')
                return false;
        }
        for (int i = row + 1, j = col + 1; i < n && j < n; ++i, ++j)
        {
            if (vs[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void dfs(vector<vector<string>>& ret, vector<string>& vs, int row, int n)
    {
        if (row == n)
        {
            ret.push_back(vs);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isVaildPos(vs, row, i, n))
            {
                vs[row][i] = 'Q';
                dfs(ret, vs, row + 1, n);
                vs[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ret;
        vector<string> vs(n, string(n, '.'));
        dfs(ret, vs, 0, n);
        return ret;
    }
};