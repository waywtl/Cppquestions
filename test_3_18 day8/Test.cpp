#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

//连续子向量最大和
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        /*vector<int> dp(array.size()+1,0);
        int ret = array[0];
        dp[0] = array[0];
        for(int i = 1; i < array.size(); ++i)
        {
            dp[i] = max(array[i], dp[i-1] + array[i]);
            ret = max(ret, dp[i]);
        }
        return ret;*/

        int total = array[0];
        int maxVal = array[0];
        for (int i = 1; i < array.size(); ++i)
        {
            if (total >= 0)
            {
                total += array[i];
            }
            else
            {
                total = array[i];
            }
            maxVal = max(maxVal, total);
        }
        return maxVal;
    }
};

//回文数索引
//写法1
bool Ispalindrome(string& str)
{
    int start = 0;
    int end = str.size() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (Ispalindrome(str))
        {
            cout << -1 << endl;
            continue;
        }
        int start = 0;
        int end = str.size() - 1;
        while (start < end)
        {
            if (str[start] != str[end])
            {
                string tmp1(str);
                tmp1 = tmp1.erase(start, 1);
                string tmp2(str);
                tmp2 = tmp2.erase(end, 1);
                if (Ispalindrome(tmp1))
                {
                    cout << start << endl;
                    break;
                }
                else
                {
                    cout << end << endl;
                    break;
                }
            }
            ++start;
            --end;
        }
    }
    return 0;
}

//写法2
bool IsPalindrome(string & str, int* start, int* end)
{
    int i = 0;
    int j = str.size() - 1;
    bool ret = true;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            ret = false;
            break;
        }
        ++i;
        --j;
    }
    if (start != nullptr)
        *start = i;
    if (start != nullptr)
        *end = j;
    return ret;
}
int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int start = 0;
        int end = 0;
        if (IsPalindrome(str, &start, &end))
        {
            cout << -1 << endl;
        }
        else
        {
            str = str.erase(start, 1);
            if (IsPalindrome(str, nullptr, nullptr))
            {
                cout << start << endl;
            }
            else
            {
                cout << end << endl;
            }
        }
    }
    return 0;
}

//把数组排成最小的数
class Solution {
public:
    static bool cmp(int x, int y)
    {
        string xs = to_string(x);
        string ys = to_string(y);
        string A = xs;
        A += ys;
        string B = ys;
        B += xs;
        return A < B;
    }

    string PrintMinNumber(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end(), cmp);
        string s = "";
        for (int i = 0; i < numbers.size(); ++i)
        {
            s += to_string(numbers[i]);
        }
        return s;
    }
};

//两个链表的第一个公共节点
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        int len1 = 0;
        int len2 = 0;
        ListNode* tmp = pHead1;
        while (tmp != nullptr)
        {
            ++len1;
            tmp = tmp->next;
        }
        tmp = pHead2;
        while (tmp != nullptr)
        {
            ++len2;
            tmp = tmp->next;
        }
        int num = abs(len1 - len2);
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        if (len1 > len2)
        {
            while (num--)
            {
                cur1 = cur1->next;
            }
        }
        else
        {
            while (num--)
            {
                cur2 = cur2->next;
            }
        }
        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};

//二叉树的深度
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};