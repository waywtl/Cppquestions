#define _CRT_SECURE_NO_WARNINGS 1

//合并K个升序链表
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* head = new ListNode();
        head->next = nullptr;
        ListNode* tail = head;

        unordered_map<int, int> numMap;
        for (int i = 0; i < lists.size(); ++i)
        {
            ListNode* cur = lists[i];
            while (cur)
            {
                ++numMap[cur->val];
                cur = cur->next;
            }
        }
        for (int i = -10000; i <= 10000; ++i)
        {
            if (numMap.find(i) != numMap.end())
            {
                int cnt = numMap[i];
                while (cnt--)
                {
                    ListNode* node = new ListNode(i);
                    node->next = nullptr;

                    tail->next = node;
                    tail = node;
                }
            }
        }
        return head->next;
    }
};

//下一个排列
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        for (i = n - 1; i > 0; --i)
        {
            if (nums[i] > nums[i - 1])
                break;
        }
        if (i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for (j = n - 1; j >= i; --j)
        {
            if (nums[j] > nums[i - 1])
            {
                int tmp = nums[j];
                nums[j] = nums[i - 1];
                nums[i - 1] = tmp;

                break;
            }
        }
        sort(nums.begin() + i, nums.end());
    }
};