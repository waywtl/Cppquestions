#define _CRT_SECURE_NO_WARNINGS 1

//乘积最大子数组
//方法1
//暴力 O(n2)
 class Solution {
 public:
     int maxProduct(vector<int>& nums)
     {
         int ans = nums[0];
         int n = nums.size();
         for(int i = 1; i < n; ++i)
         {
             int mul = nums[i];
             for(int j = i-1; j >= 0; --j)
             {
                 ans = max(ans, mul);
                 mul *= nums[j];
                 ans = max(ans, mul);
             }
         }
         return ans;
     }
 };

 //方法2
 //动态规划，维护dp_max以及dp_min
 class Solution {
 public:
     int maxProduct(vector<int>& nums)
     {
         int ans = nums[0];
         int dp_max = nums[0];
         int dp_min = nums[0];
         for(int i = 1; i < nums.size(); ++i)
         {
             int pre_max = dp_max;
             dp_max = max(pre_max*nums[i], max(nums[i], dp_min*nums[i]));
             dp_min = min(pre_max*nums[i], min(nums[i], dp_min*nums[i]));
             ans = max(ans, dp_max);
         }
         return ans;
     }
 };

 //方法3
 //讨论负数的奇偶
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = nums[0];
        int n = nums.size();
        int mul = 1;
        for (int i = 0; i < n; ++i)
        {
            mul *= nums[i];
            ans = max(ans, mul);
            if (mul == 0)
                mul = 1;
        }

        mul = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            mul *= nums[i];
            ans = max(ans, mul);
            if (mul == 0)
                mul = 1;
        }

        return ans;
    }
};

//多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int cnt = 1;
        int ans = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (cnt == 0)
                ans = nums[i];
            if (nums[i] == ans)
                ++cnt;
            else
                --cnt;
        }
        return ans;
    }
};