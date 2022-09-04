#define _CRT_SECURE_NO_WARNINGS 1

//检查相同字母间的距离
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance)
    {
        map<char, pair<int, int>> m;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];

            if (m.find(ch) == m.end())
                m[ch].first = i;
            else
            {
                m[ch].second = i;
            }
        }

        bool ret = true;
        for (int i = 0; i < distance.size(); ++i)
        {

            if (m.find(i + 'a') != m.end())
            {
                auto p = m[i + 'a'];
                if (p.second - p.first - 1 != distance[i])
                {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }
};

//恰好移动k步到达某一位置的方法数目
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        vector<vector<int>> dp(k + 1, vector<int>(3000, 0));
        dp[0][startPos + 999] = 1;
        for (int i = 1; i < k + 1; ++i)
        {
            for (int j = 0; j < 3000; ++j)
            {
                dp[i][j] = ((j > 1 ? dp[i - 1][j - 1] : 0) + (j + 1 < 3000 ? dp[i - 1][j + 1] : 0)) % 1000000007;
            }
        }
        return dp[k][endPos + 999];
    }
};

//最长优雅子数组
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int or_ = 0;
            int j = i;
            while (j >= 0 && (or_ & nums[j]) == 0)
                or_ |= nums[j--];
            ans = max(ans, i - j);
        }
        return ans;
    }
};

//会议室Ⅲ 
//此解法不能ac，最后一个测试用例过不了
class Solution {
public:
    typedef long long ll;
    struct meet
    {
        int cnt = 0;
        bool use = false;
        ll start = 0;
        ll end = 0;
    };

    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<meet> v(n);
        int ret = 0;
        for (auto& p : meetings)
        {
            ll min_end = INT_MAX;
            bool uses = false;
            int index = -1;
            for (int i = 0; i < n; ++i)
            {
                if (v[i].use && v[i].end < min_end && min_end > p[0])
                {
                    min_end = v[i].end;
                    index = i;
                }
                if (v[i].use && p[0] >= v[i].end)
                {
                    uses = true;
                    v[i].cnt++;
                    v[i].start = p[0];
                    v[i].end = v[i].start + p[1] - p[0];
                    break;
                }
                if (!v[i].use)
                {
                    uses = true;
                    v[i].cnt++;
                    v[i].use = true;
                    v[i].start = v[i].start + p[0];
                    v[i].end = v[i].end + p[1];
                    break;
                }
            }
            if (!uses && index != -1)
            {
                v[index].cnt++;
                v[index].start = v[index].end;
                v[index].end = v[index].start + p[1] - p[0];
            }
        }
        int max_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i].cnt > max_cnt)
            {
                max_cnt = v[i].cnt;
                ret = i;
            }
        }
        return ret;
    }
};