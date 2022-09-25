#define _CRT_SECURE_NO_WARNINGS 1

//按身高排序
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();
        vector<string> ans;
        unordered_map<int, string> m;
        for (int i = 0; i < n; ++i)
        {
            m[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end());
        for (int i = n - 1; i >= 0; --i)
        {
            ans.push_back(m[heights[i]]);
        }
        return ans;
    }
};

//按位与最大的最长子数组
class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int ans = 0;
        int ands = 0;
        int l = 0;
        int n = nums.size();


        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > ands)
            {
                ans = 1;
                ands = nums[i];
                l = i;
            }
            else if (nums[i] == ands)
                ans = max(ans, i - l + 1);
            else
                l = i + 1;
        }
        return ans;
    }
};

//找到所有好下标
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> del(n, 1);

        for (int i = 2; i < n; ++i)
        {
            if (nums[i - 1] <= nums[i - 2])
                del[i] = del[i - 1] + 1;
        }

        vector<int> add(n, 1);
        for (int i = n - 3; i >= 0; --i)
        {
            if (nums[i + 1] <= nums[i + 2])
                add[i] = add[i + 1] + 1;
        }

        for (int i = k; i < n - k; ++i)
        {
            if (del[i] >= k && add[i] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};