#define _CRT_SECURE_NO_WARNINGS 1

//从字符串中移除星号
class Solution {
public:
    string removeStars(string s)
    {
        stack<char> st;
        for (auto& c : s)
        {
            if (c != '*')
                st.push(c);
            else
            {
                st.pop();
            }
        }
        string ans;
        while (!st.empty())
        {
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//收集垃圾的最少总时间
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int ans = 0;
        for (auto& s : garbage)
            ans += s.size();

        int n = garbage.size();
        int i = n - 1;
        int j = 0;
        for (; i >= 0; --i)
        {
            string s = garbage[i];
            if (s.find('G') != string::npos)
                break;
        }

        while (j < i)
        {
            ans += travel[j];
            ++j;
        }

        i = n - 1;
        j = 0;
        for (; i >= 0; --i)
        {
            string s = garbage[i];
            if (s.find('P') != string::npos)
                break;
        }

        while (j < i)
        {
            ans += travel[j];
            ++j;
        }

        i = n - 1;
        j = 0;
        for (; i >= 0; --i)
        {
            string s = garbage[i];
            if (s.find('M') != string::npos)
                break;
        }

        while (j < i)
        {
            ans += travel[j];
            ++j;
        }

        return ans;
    }
};