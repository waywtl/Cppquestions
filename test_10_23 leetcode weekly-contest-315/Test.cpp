#define _CRT_SECURE_NO_WARNINGS 1

//与对应负数同时存在的最大正整数
class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == 0 && abs(nums[i]) > ans)
                {
                    ans = abs(nums[i]);
                }
            }
        }
        return ans;
    }
};

//反转之后不同整数的数目
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            string str = to_string(nums[i]);
            int num = 0;
            int len = str.size();
            for (int j = len - 1; j >= 0; --j)
            {
                num *= 10;
                num += (str[j] - '0');
            }
            s.insert(num);
        }
        return s.size();
    }
};

//反转之后的数字和
class Solution {
public:
    bool sumOfNumberAndReverse(int target)
    {
        bool ans = false;
        for (int num = 0; num <= target; ++num)
        {
            string str = to_string(num);
            int r_num = 0;
            int len = str.size();
            for (int j = len - 1; j >= 0; --j)
            {
                r_num *= 10;
                r_num += (str[j] - '0');
            }
            if (num + r_num == target)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};