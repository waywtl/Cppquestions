#define _CRT_SECURE_NO_WARNINGS 1

//重构链表
class Solution {
public:
    ListNode* reContruct(ListNode* head)
    {
        while (head != nullptr && head->val % 2 == 0)
            head = head->next;

        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur)
        {
            if (cur->val % 2 == 0)
            {
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

//勘探补给
class Solution {
public:
    vector<int> explorationSupply(vector<int>& station, vector<int>& pos)
    {
        int n = station.size();
        int m = pos.size();
        vector<int> ans(m, 0);

        for (int i = 0; i < m; ++i)
        {
            int index = lower_bound(station.begin(), station.end(), pos[i]) - station.begin();

            if (index > 0 && (index == n || pos[i] - station[index - 1] <= station[index] - pos[i]))
                ans[i] = index - 1;
            else
                ans[i] = index;
        }
        return ans;
    }
};

//风能发电
class Solution {
public:
    int StoredEnergy(int storeLimit, const vector<int>& power, const vector<vector<int>>& supply)
    {

        int n = supply.size();
        int m = power.size();
        int total = 0;
        int cur = 0;
        int cur_min = supply[0][1];
        int cur_max = supply[0][2];

        for (int i = 0; i < m; ++i)
        {
            if (cur < n - 1 && i == supply[cur + 1][0])
            {
                ++cur;
                cur_min = supply[cur][1];
                cur_max = supply[cur][2];
            }

            if (power[i] > cur_max)
            {
                total += (power[i] - cur_max);
                total = total > storeLimit ? storeLimit : total;
            }
            else if (power[i] < cur_min)
            {
                total -= (cur_min - power[i]);
                total = total < 0 ? 0 : total;
            }
        }
        return total;
    }
};