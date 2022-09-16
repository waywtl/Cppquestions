#define _CRT_SECURE_NO_WARNINGS 1

//¾ØÐÎÃæ»ý¢ò
class Solution {
public:
    bool check(vector<int>& v1, vector<vector<int>>& v2)
    {
        int x1 = v1[0], x2 = v1[2], y1 = v1[1], y2 = v1[3];
        for (auto& v : v2)
        {
            if (x1 >= v[0] && x1 <= v[2] && x2 >= v[0] && x2 <= v[2] && y1 >= v[1] && y1 <= v[3] && y2 >= v[1] && y2 <= v[3])
                return true;
        }
        return false;
    }

    int rectangleArea(vector<vector<int>>& rectangles)
    {
        const int MOD = 1e9 + 7;
        sort(rectangles.begin(), rectangles.end());
        long long ans = 0;

        set<int> st;
        for (auto& v : rectangles)
        {
            st.insert(v[0]);
            st.insert(v[2]);
        }
        vector<int> v1(st.begin(), st.end());

        st.clear();
        for (auto& v : rectangles)
        {
            st.insert(v[1]);
            st.insert(v[3]);
        }
        vector<int> v2(st.begin(), st.end());
        int n = v1.size();
        int m = v2.size();

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < m - 1; ++j)
            {
                vector<int> v = { v1[i], v2[j], v1[i + 1], v2[j + 1] };
                if (check(v, rectangles))
                    ans += (long long)(v[2] - v[0]) * (v[3] - v[1]);
            }
            ans %= MOD;
        }
        return ans;
    }
};

//Ç×ÃÜ×Ö·û´®
class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        int len1 = s.size();
        int len2 = goal.size();
        if (len1 != len2)
            return false;

        vector<int> v;
        for (int i = 0; i < len1; ++i)
        {
            if (s[i] != goal[i])
                v.push_back(i);
        }

        int n = v.size();
        if (n == 0)
        {
            int a[27] = { 0 };
            for (auto& ch : s)
            {
                ++a[ch - 'a'];
                if (a[ch - 'a'] >= 2)
                    return true;
            }
            return false;
        }
        else if (n == 1 || n > 2)
            return false;
        else
            return s[v[0]] == goal[v[1]] && s[v[1]] == goal[v[0]];
    }
};