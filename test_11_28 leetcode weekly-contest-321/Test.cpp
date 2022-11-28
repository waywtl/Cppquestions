#define _CRT_SECURE_NO_WARNINGS 1

//2485. �ҳ��������� ��ʾӢ������
//
//��Ŀ�Ѷ�Easy
//����һ�������� n ���ҳ��������������� �������� x ��
//
//1 �� x ֮�������Ԫ��֮�͵��� x �� n ֮������Ԫ��֮�͡�
//������������ x ����������������������򷵻� - 1 ����Ŀ��֤���ڸ��������룬�������һ������������

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


//2486. ׷���ַ��Ի�������� ��ʾӢ������
//
//��Ŀ�Ѷ�Medium
//������������СдӢ����ĸ��ɵ��ַ��� s �� t ��
//
//������Ҫͨ���� s ĩβ׷���ַ��ķ�ʽʹ t ��� s ��һ�� ������ ��������Ҫ׷�ӵ������ַ�����
//
//��������һ�������������ַ���ɾ�����֣���ɾ�����ַ������ı�ʣ���ַ�˳��õ����ַ�����

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


//2487. ���������Ƴ��ڵ� ��ʾӢ������
//
//��Ŀ�Ѷ�Medium
//����һ�������ͷ�ڵ� head ��
//
//�����б��е�ÿ���ڵ� node ��������Ҳ����һ������ �ϸ���� ֵ�Ľڵ㣬���Ƴ� node ��
//
//�����޸ĺ������ͷ�ڵ� head ��

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


//2488. ͳ����λ��Ϊ K �������� ��ʾӢ������
//
//��Ŀ�Ѷ�Hard
//����һ������Ϊ n ������ nums ���������ɴ� 1 �� n �� ��ͬ ������ɡ������һ�������� k ��
//
//ͳ�Ʋ����� num �е� ��λ�� ���� k �ķǿ����������Ŀ��
//
//ע�⣺
//
//�������λ���ǰ� ���� ˳�����к�λ�� �м� ���Ǹ�Ԫ�أ�������鳤��Ϊż��������λ����λ���м俿 �� ���Ǹ�Ԫ�ء�
//���磬[2, 3, 1, 4] ����λ���� 2 ��[8, 4, 3, 5, 1] ����λ���� 4 ��
//�������������е�һ���������֡�

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