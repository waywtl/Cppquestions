#define _CRT_SECURE_NO_WARNINGS 1

//特殊数组的特征值
class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        int a[1001] = { 0 };
        for (auto& x : nums)
            ++a[x];

        for (int i = 999; i >= 0; --i)
            a[i] += a[i + 1];

        for (int i = n; i >= 0; --i)
        {
            if (a[i] == i)
                return i;
        }
        return -1;
    }
};

//和相等的子数组
class Solution {
public:
    bool findSubarrays(vector<int>& nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int sum = nums[i] + nums[i + 1];
            m[sum]++;
            if (m[sum] > 1)
                return true;
        }
        return false;
    }
};

//严格回文的数字
class Solution {
public:
    bool isStrictlyPalindromic(int n)
    {
        return false;
    }
};