#define _CRT_SECURE_NO_WARNINGS 1

//寻找重复数
//建立 n->f(n) 的映射，类比成带环链表
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int head = 0;
        while (head != slow)
        {
            head = nums[head];
            slow = nums[slow];
        }
        return slow;
    }
};

//最长递增子序列
//用tail[i] 保存长度为 i 的递增子序列中最小的尾部元素
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> tail(n + 1, 0);
        int len = 1;
        tail[1] = nums[0];

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > tail[len])
                tail[++len] = nums[i];
            else
            {
                int left = 1;
                int right = len;
                int pos = 0;
                while (left <= right)
                {
                    int mid = (left + right) >> 1;
                    if (tail[mid] < nums[i])
                        left = mid + 1;
                    else
                    {
                        pos = mid;
                        right = mid - 1;
                    }
                }
                tail[pos] = nums[i];
            }
        }
        return len;
    }
};