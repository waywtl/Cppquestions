#define _CRT_SECURE_NO_WARNINGS 1

//两数相加
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ret = new ListNode;
        ListNode* cur = ret;
        int more = 0;
        while (l1 && l2)
        {
            int num = l1->val + l2->val + more;
            int x = num % 10;
            more = num / 10;
            ListNode* node = new ListNode(x);
            cur->next = node;
            cur = node;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int num = l1->val + more;
            int x = num % 10;
            more = num / 10;
            ListNode* node = new ListNode(x);
            cur->next = node;
            cur = node;
            l1 = l1->next;
        }

        while (l2)
        {
            int num = l2->val + more;
            int x = num % 10;
            more = num / 10;
            ListNode* node = new ListNode(x);
            cur->next = node;
            cur = node;
            l2 = l2->next;
        }

        if (more)
        {
            ListNode* node = new ListNode(more);
            cur->next = node;
        }
        return ret->next;
    }
};

//无重复字符的最长字串
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int a[256] = { 0 };
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        while (i < n && j < n)
        {
            int index = s[j];
            ++a[index];
            while (a[index] > 1)
                --a[s[i++]];

            ans = max(ans, j - i + 1);
            ++j;
        }
        return ans;
    }
};