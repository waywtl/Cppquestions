#define _CRT_SECURE_NO_WARNINGS 1

//统计定界子数组的数目
//特殊指分割 + 枚举右端点
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        long long ans = 0;
        int min_i = -1;
        int max_i = -1;
        int i0 = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == minK)
                min_i = i;
            if (nums[i] == maxK)
                max_i = i;
            if (nums[i] < minK || nums[i] > maxK)
                i0 = i;

            ans += max(min(min_i, max_i) - i0, 0);
        }
        return ans;
    }
};