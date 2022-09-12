#define _CRT_SECURE_NO_WARNINGS 1

//出现最频繁的偶数元素
class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        int arr[100001] = { 0 };
        for (auto& x : nums)
        {
            if (x % 2 == 0 || x == 0)
                arr[x]++;
        }

        int ans = 0;
        bool flag = false;
        for (int i = 0; i < 100001; ++i)
        {
            if (arr[i] != 0)
            {
                flag = true;
                if (arr[i] > arr[ans])
                    ans = i;
            }
        }
        if (!flag)
            return -1;
        return ans;
    }
};

//子字符串的最优划分
class Solution {
public:
    int partitionString(string s)
    {
        int ans = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (m.find(ch) != m.end())
            {
                ++ans;
                m.clear();
                i -= 1;
                continue;
            }
            m[ch]++;
        }
        return ans + 1;
    }
};

//将区间分为最少组数
class Solution {
public:
    int minGroups(vector<vector<int>>& vv)
    {
        sort(vv.begin(), vv.end());
        int n = vv.size();
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (q.size() == 0)
            {
                q.push(vv[i][1]);
                continue;
            }
            int left = vv[i][0];

            if (left <= q.top())
                q.push(vv[i][1]);
            else
            {
                q.pop();
                q.push(vv[i][1]);
            }
        }
        return q.size();
    }
};

//最长递增子序列Ⅱ
