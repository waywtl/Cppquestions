#define _CRT_SECURE_NO_WARNINGS 1

//打家劫舍
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        dp[2] = nums[1];
        int ans = max(dp[1], dp[2]);
        for (int i = 3; i < n + 1; ++i)
        {
            dp[i] = nums[i - 1] + max(dp[i - 2], dp[i - 3]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//课程表
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> nums(numCourses);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            ++nums[prerequisites[i][0]];
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (nums[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            ++cnt;
            vector<int> v = m[course];
            for (int i = 0; i < v.size(); ++i)
            {
                --nums[v[i]];
                if (nums[v[i]] == 0)
                    q.push(v[i]);
            }
        }
        if (cnt == numCourses)
            return true;
        return false;
    }
};