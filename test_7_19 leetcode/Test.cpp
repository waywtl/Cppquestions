#define _CRT_SECURE_NO_WARNINGS 1

//在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    int BinarySearch(const vector<int>& nums, int target, int flag)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ret = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (flag && nums[mid] >= target))
            {
                right = mid - 1;
                ret = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left_index = BinarySearch(nums, target, 1);
        int right_index = BinarySearch(nums, target, 0) - 1;
        if (left_index <= right_index && right_index < nums.size() && nums[left_index] == target && nums[right_index] == target)
            return { left_index, right_index };
        return { -1, -1 };
    }
};

//接雨水
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);

        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i)
        {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i)
        {
            right_max[i] = max(right_max[i + 1], height[i + 1]);
        }

        int water = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            int tmp = min(left_max[i], right_max[i]) - height[i];
            if (tmp > 0)
                water += tmp;
        }
        return water;
    }
};
