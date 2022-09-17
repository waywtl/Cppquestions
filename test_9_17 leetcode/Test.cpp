#define _CRT_SECURE_NO_WARNINGS 1

//两个相同字符之间的最长子字符串
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        map<char, vector<int>> m;
        for (int i = 0; i < s.size(); ++i)
        {
            m[s[i]].push_back(i);
        }

        int ans = -1;
        for (auto& [ch, v] : m)
        {
            int n = v.size();
            if (n >= 2 && v[n - 1] - v[0] > ans)
                ans = v[n - 1] - v[0] - 1;
        }
        return ans;
    }
};

//预算内的最多机器人数目
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        deque<int> q;
        long long sum = 0;
        int ans = 0;
        for (int i = 0, j = 0; j < n; ++j)
        {
            while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[j])
                q.pop_back();
            q.push_back(j);
            sum += runningCosts[j];

            while (!q.empty() && chargeTimes[q.front()] + (j - i + 1) * sum > budget)
            {
                if (q.front() == i)
                    q.pop_front();
                sum -= runningCosts[i++];
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//自己写的
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int i = 0, j = 0;

        deque<int> q;
        q.push_back(j);
        long long sum_rc = runningCosts[0];
        int max_ct = 0;
        long long cost = 0;
        int ans = 0;
        while (i < n && j < n)
        {
            max_ct = chargeTimes[q.front()];
            cost = max_ct + (long long)(j - i + 1) * sum_rc;
            if (j < n && cost <= budget)
            {
                ans = max(ans, j - i + 1);
                ++j;
                if (j == n)
                    continue;
                sum_rc += runningCosts[j];
                while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[j])
                    q.pop_back();
                q.push_back(j);
            }
            else
            {
                ++i;
                sum_rc -= runningCosts[i - 1];
                while (!q.empty() && q.front() < i)
                    q.pop_front();
            }
            if (j < i && i < n)
            {
                j = i;
                q.push_back(j);
                sum_rc += runningCosts[j];
            }
        }
        return ans;
    }
};