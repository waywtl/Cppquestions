#define _CRT_SECURE_NO_WARNINGS 1

//字符串轮转
//方法一：暴力
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n)
            return false;
        if (n == 0)
            return true;

        vector<int> index;
        for (int i = 0; i < n; ++i)
        {
            if (s2[i] == s1[0])
                index.push_back(i);
        }
        int j = 0;
        for (int i = 0; i < index.size(); ++i)
        {
            j = index[i];
            string str1 = s2.substr(j);
            string str2 = s2.substr(0, j);
            if (str1 + str2 == s1)
                return true;
        }
        return false;
    }
};

//方法2：两倍s1中找s2
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
    }
};

//课程表Ⅱ
//方法1：拓扑排序 dfs
class Solution {
public:
    vector<vector<int>> g;
    vector<int> book;
    vector<int> res;
    bool flag = true;

    void dfs(int i)
    {
        book[i] = 1;
        for (auto& x : g[i])
        {
            if (book[x] == 0)
            {
                dfs(x);
                if (!flag)
                    return;
            }
            else if (book[x] == 1)
            {
                flag = false;
                return;
            }
        }

        book[i] = 2;
        res.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        book.resize(numCourses, 0);

        for (auto& v : prerequisites)
            g[v[1]].push_back(v[0]);

        for (int i = 0; i < numCourses; ++i)
        {
            if (!book[i])
            {
                dfs(i);
            }
        }

        if (!flag)
            return {};

        reverse(res.begin(), res.end());
        return res;
    }
};

//方法2：bfs
class Solution {
public:
    vector<vector<int>> g;
    vector<int> book;
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        book.resize(numCourses, 0);

        for (auto& v : prerequisites)
        {
            g[v[1]].push_back(v[0]);
            ++book[v[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (book[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            res.push_back(i);
            for (int x : g[i])
            {
                --book[x];
                if (book[x] == 0)
                    q.push(x);
            }
        }

        if (res.size() != numCourses)
            return {};

        return res;
    }
};