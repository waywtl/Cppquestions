#define _CRT_SECURE_NO_WARNINGS 1

//银行中的激光束数量
class Solution {
public:
    int CntOfOne(const string& s)
    {
        int cnt = 0;
        for (auto& ch : s)
        {
            if (ch == '1')
                ++cnt;
        }
        return cnt;
    }

    int numberOfBeams(vector<string>& bank)
    {
        int n = bank.size();
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < n; ++i)
        {
            string s = bank[i];
            int cur = CntOfOne(s);
            if (cur == 0)
                continue;
            if (pre != 0)
                ans += (pre * cur);
            pre = cur;
        }
        return ans;
    }
};

//增减字符串匹配
class Solution {
public:
    vector<int> diStringMatch(string s)
    {
        s += 'D';
        int n = s.size();
        vector<int> ans(n, -1);
        int num = 0;
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'I')
            {
                index = i - 1;
                ans[i] = num++;
                while (index >= 0 && ans[index] == -1)
                    ans[index--] = num++;
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (ans[i] != -1)
                break;
            ans[i] = num++;
        }
        
        return ans;
    }
};