#define _CRT_SECURE_NO_WARNINGS 1

//第k个数
class Solution {
public:
    int getKthMagicNumber(int k)
    {
        set<long long> nums;
        nums.insert(1);
        int cnt = k;
        for (auto& x : nums)
        {
            nums.insert(3 * x);
            nums.insert(5 * x);
            nums.insert(7 * x);
            cnt--;
            if (cnt == 0)
                break;
        }

        long long ans = 0;
        cnt = k - 1;
        for (auto& x : nums)
        {
            if (cnt == 0)
            {
                ans = x;
                break;
            }
            --cnt;
        }
        return ans;

    }
};

//最长回文子串
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (s[i] == s[j] && (dp[i - 1][j + 1] || j + 1 > i - 1))
                {
                    dp[i][j] = true;
                    if (i - j + 1 > end - start + 1)
                    {
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

//罗马数字转整数
class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        int i = 0;
        int n = s.size();
        while (i < n)
        {
            if (m[s[i]] >= m[s[i + 1]])
            {
                ans += m[s[i]];
                ++i;
            }
            else
            {
                ans += (m[s[i + 1]] - m[s[i]]);
                i += 2;
            }
        }
        return ans;
    }
};

//最长公共前缀
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = strs[0];
        if (ans == "")
            return ans;
        int len = ans.size();
        int end = len;
        int n = strs.size();
        for (int i = 1; i < n; ++i)
        {
            int m = strs[i].size();
            int j = 0;
            int min_len = min(len, m);
            for (; j < min_len; ++j)
            {
                if (ans[j] != strs[i][j])
                {
                    end = min(j - 1, end);
                    break;
                }
            }
            end = min(j - 1, end);
        }
        return ans.substr(0, end + 1);
    }
};