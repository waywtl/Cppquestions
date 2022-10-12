#define _CRT_SECURE_NO_WARNINGS 1

//处理用时最长的那个任务的员工
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs)
    {
        int ans = logs[0][0];
        int _max = logs[0][1];
        for (int i = 1; i < logs.size(); ++i)
        {
            if (logs[i][1] - logs[i - 1][1] > _max)
            {
                _max = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            }
            else if (logs[i][1] - logs[i - 1][1] == _max && logs[i][0] < ans)
            {
                ans = logs[i][0];
            }
        }
        return ans;
    }
};

//找出前缀异或的原始数组
class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        vector<int> ans;
        int _xor = pref[0];
        ans.push_back(_xor);
        for (int i = 1; i < pref.size(); ++i)
        {
            int num = _xor ^ pref[i];
            ans.push_back(num);
            _xor ^= num;
        }
        return ans;
    }
};

//使用机器人打印字典序最小的字符串
class Solution {
public:
    string robotWithString(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;

        vector<int> book(n, 0);
        book[n - 2] = n - 1;
        for (int i = n - 3; i >= 0; --i)
        {
            book[i] = book[i + 1];
            if (s[i + 1] < s[book[i + 1]])
            {
                book[i] = i + 1;
            }
        }

        string ans;
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            st.push(i);
            while (!st.empty() && s[st.top()] <= s[book[i]])
            {
                char ch = s[st.top()];
                st.pop();
                ans += ch;
            }
        }

        while (!st.empty())
        {
            char ch = s[st.top()];
            st.pop();
            ans += ch;
        }
        return ans;
    }
};