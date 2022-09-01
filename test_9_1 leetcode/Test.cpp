#define _CRT_SECURE_NO_WARNINGS 1

//反转每队括号间的子串
//方法一：栈 O(n2)
class Solution {
public:
    string reverseParentheses(string s)
    {
        int len = s.size();
        stack<string> st;
        string str;
        for (auto& ch : s)
        {
            if (ch == '(')
            {
                st.push(str);
                str = "";
            }
            else if (ch == ')')
            {
                reverse(str.begin(), str.end());
                str = st.top() + str;
                st.pop();
            }
            else
                str += ch;
        }
        return str;
    }
};

//方法二: 对向跳跃遍历 O(n)
class Solution {
public:
    string reverseParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                int j = st.top();
                st.pop();
                v[i] = j;
                v[j] = i;
            }
        }

        string ans;
        for (int i = 0, d = 1; i < n; i += d)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = v[i];
                d = -d;
            }
            else
                ans += s[i];
        }
        return ans;
    }
};

//设计一个验证系统
class AuthenticationManager {
public:
    int time;
    unordered_map<string, int> m;
    AuthenticationManager(int timeToLive)
    {
        time = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        m[tokenId] = currentTime + time;
    }

    void renew(string tokenId, int currentTime)
    {
        if (m.find(tokenId) != m.end() && m[tokenId] > currentTime)
            m[tokenId] = currentTime + time;
    }

    int countUnexpiredTokens(int currentTime)
    {
        int cnt = 0;
        for (auto& p : m)
        {
            if (p.second > currentTime)
                ++cnt;
        }
        return cnt;
    }
};