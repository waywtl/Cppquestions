#define _CRT_SECURE_NO_WARNINGS 1

//É¾³ýÎÞÐ§µÄÀ¨ºÅ
class Solution {
public:
    void dfs(string s, unordered_set<string>& ret)
    {
        int count = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            char ch = s[i];
            if (ch == '(')
                ++count;
            if (ch == ')')
                --count;
            if (count < 0)
            {
                for (int j = 0; j <= i; ++j)
                {
                    if (j > 0 && s[j - 1] == ')')
                        continue;
                    if (s[j] == ')')
                    {
                        string tmp = s;
                        dfs(tmp.erase(j, 1), ret);
                    }
                }
                return;
            }
            if (i == size - 1 && count == 0)
                ret.insert(s);
        }

        count = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            char ch = s[i];
            if (ch == ')')
                ++count;
            if (ch == '(')
                --count;
            if (count < 0)
            {
                for (int j = size - 1; j >= i; --j)
                {
                    if (j < size - 1 && s[j + 1] == '(')
                        continue;
                    if (s[j] == '(')
                    {
                        string tmp = s;
                        dfs(tmp.erase(j, 1), ret);
                    }
                }
                return;
            }
            if (i == 0 && count == 0)
                ret.insert(s);
        }
        return;
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ret;
        dfs(s, ret);
        vector<string> ans;
        for (auto& s : ret)
            ans.push_back(s);
        if (ans.size() == 0)
            ans.push_back("");
        return ans;
    }
};