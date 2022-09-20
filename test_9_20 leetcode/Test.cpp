#define _CRT_SECURE_NO_WARNINGS 1

//划分为k个相等的子集
class Solution {
public:
    bool dfs(vector<int>& nums, int index, vector<int>& sums, int k, int sum)
    {
        if (index == nums.size())
            return true;

        for (int i = 0; i < k; ++i)
        {
            if (sums[i] + nums[index] > sum || (i && sums[i] == sums[i - 1]))
                continue;

            sums[i] += nums[index];
            if (dfs(nums, index + 1, sums, k, sum))
                return true;
            sums[i] -= nums[index];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        if (k == 1)
            return true;
        int sum = 0;
        for (auto& x : nums)
            sum += x;

        if (sum % k != 0)
            return false;

        sum /= k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<int> sums(k, 0);
        return dfs(nums, 0, sums, k, sum);
    }
};


//蓝桥杯2021年第十二届国赛真题-和与乘积
#include<iostream>
#include <vector>
#include <deque>
using namespace std;

int BS(vector<int>& pre, int target, int begin, int end)
{
    int l = begin;
    int r = end;
    int m = 0;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (pre[m] == target)
            return m;
        else if (pre[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int solve(vector<int>& nums)
{
    int n = nums.size();
    int ans = 0;
    deque<pair<int, int>> muls;
    vector<int> pre(n + 1, 0);

    for (int i = 1; i < n + 1; ++i)
        pre[i] = pre[i - 1] + nums[i - 1];

    for (int i = 0; i < n; ++i)
    {
        muls.push_front({ 1, i });
        int k = 0;
        for (int j = 0; j < muls.size(); ++j)
        {
            muls[j].first *= nums[i];
            if (muls[k].first == muls[j].first)
                muls[k].second = muls[j].second;
            else
            {
                ++k;
                muls[k] = muls[j];
            }
        }

        muls.resize(k + 1);

        int r = i;
        for (auto& p : muls)
        {
            int l = p.second;
            int idx = BS(pre, pre[i + 1] - p.first, l, r);
            if (idx != -1)
                ++ans;
            r = l - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << solve(nums) << endl;
    return 0;
}