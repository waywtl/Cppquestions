#define _CRT_SECURE_NO_WARNINGS 1

//2485. 找出中枢整数 显示英文描述
//
//题目难度Easy
//给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：
//
//1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
//返回中枢整数 x 。如果不存在中枢整数，则返回 - 1 。题目保证对于给定的输入，至多存在一个中枢整数。

class Solution {
public:
    int pivotInteger(int n)
    {
        int ans = -1;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += i;

        int tmp = 0;
        for (int i = 1; i <= n; ++i)
        {
            tmp += i;
            if (tmp * 2 == (sum + i))
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


//2486. 追加字符以获得子序列 显示英文描述
//
//题目难度Medium
//给你两个仅由小写英文字母组成的字符串 s 和 t 。
//
//现在需要通过向 s 末尾追加字符的方式使 t 变成 s 的一个 子序列 ，返回需要追加的最少字符数。
//
//子序列是一个可以由其他字符串删除部分（或不删除）字符但不改变剩下字符顺序得到的字符串。

class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;
        int s_n = s.size();
        int t_n = t.size();

        while (i < s_n && j < t_n)
        {
            if (s[i] == t[j])
            {
                ++i;
                ++j;
            }
            else
                ++i;
        }
        return t_n - j;
    }
};


//2487. 从链表中移除节点 显示英文描述
//
//题目难度Medium
//给你一个链表的头节点 head 。
//
//对于列表中的每个节点 node ，如果其右侧存在一个具有 严格更大 值的节点，则移除 node 。
//
//返回修改后链表的头节点 head 。

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
    ListNode* removeNodes(ListNode* head)
    {
        vector<int> v;
        ListNode* cur = head;
        while (cur)
        {
            v.push_back(cur->val);
            cur = cur->next;
        }

        int n = v.size();
        vector<int> ans;

        int tar = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (tar > v[i])
                continue;
            else
            {
                tar = v[i];
                ans.push_back(tar);
            }
        }
        reverse(ans.begin(), ans.end());
        ListNode* ret = new ListNode(0);
        cur = ret;
        for (int i = 0; i < ans.size(); ++i)
        {
            ListNode* newNode = new ListNode(ans[i]);
            cur->next = newNode;
            cur = newNode;
        }
        return ret->next;
    }
};


//2488. 统计中位数为 K 的子数组 显示英文描述
//
//题目难度Hard
//给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。
//
//统计并返回 num 中的 中位数 等于 k 的非空子数组的数目。
//
//注意：
//
//数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
//例如，[2, 3, 1, 4] 的中位数是 2 ，[8, 4, 3, 5, 1] 的中位数是 4 。
//子数组是数组中的一个连续部分。

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k)
    {
        int ans = 1;
        int cnt_more = 0;
        int cnt_less = 0;

        int index = 0;
        int n = nums.size();
        while (index < n && nums[index] != k)
            ++index;

        unordered_map<int, int> r_m;
        r_m[0] = 1;
        for (int i = index + 1; i < n; ++i)
        {
            if (nums[i] > k)
                ++cnt_more;
            else
                ++cnt_less;

            ++r_m[cnt_more - cnt_less];
        }

        cnt_more = 0;
        cnt_less = 0;
        unordered_map<int, int> l_m;
        l_m[0] = 1;
        for (int i = index - 1; i >= 0; --i)
        {
            if (nums[i] > k)
                ++cnt_more;
            else
                ++cnt_less;

            ++l_m[cnt_more - cnt_less];
        }

        for (auto& p : l_m)
        {
            auto cur = r_m.find(-p.first);
            if (cur != r_m.end())
                ans += (p.second * cur->second);

            cur = r_m.find(-p.first + 1);
            if (cur != r_m.end())
                ans += (p.second * cur->second);
        }
        return ans - 1;
    }
};