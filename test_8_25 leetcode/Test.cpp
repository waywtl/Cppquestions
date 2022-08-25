#define _CRT_SECURE_NO_WARNINGS 1

//最短无序连续子数组
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0;
        int r = 1;
        int max_num = nums[0];
        int min_num = nums[n - 1];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] >= max_num)
                max_num = nums[i];
            else
                l = i;

            if (nums[n - i - 1] <= min_num)
                min_num = nums[n - i - 1];
            else
                r = n - i - 1;
        }
        return l - r + 1;
    }
};

//任务调度器
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int len = tasks.size();
        int arr[26] = { 0 };
        for (auto& ch : tasks)
            ++arr[ch - 'A'];

        int cnt = 1;
        int m = arr[0];
        for (int i = 1; i < 26; ++i)
        {
            if (arr[i] > m)
            {
                m = arr[i];
                cnt = 1;
            }
            else if (arr[i] == m)
            {
                cnt += 1;
            }
        }
        return max(len, cnt + (m - 1) * (n + 1));
    }
};