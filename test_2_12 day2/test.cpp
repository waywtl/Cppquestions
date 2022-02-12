#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//替换空格
class Solution {
public:
    void replaceSpace(char* str, int length)
    {
        int spaceNum = 0;
        char* start = str;
        while (*start)
        {
            if (*start == ' ')
                ++spaceNum;
            start++;
        }
        char* oldEnd = str + length;
        char* newEnd = str + length + spaceNum * 2;
        while (oldEnd >= str && newEnd >= str)
        {
            if (*oldEnd != ' ')
            {
                *newEnd-- = *oldEnd--;
            }
            else
            {
                *newEnd-- = '0';
                *newEnd-- = '2';
                *newEnd-- = '%';
                oldEnd--;
            }
        }
    }
};

//从尾到头打印链表
class Solution {
public:
    void printListFromTailToHeadHelper(ListNode* head, vector <int>& arr)
    {
        if (head == nullptr)
        {
            return;
        }
        printListFromTailToHeadHelper(head->next, arr);
        arr.push_back(head->val);
    }

    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector <int> arr;
        if (head == nullptr)
        {
            return arr;
        }
        printListFromTailToHeadHelper(head, arr);
        return arr;
    }
};

//重建二叉树
class Solution {
public:
    TreeNode* reConstructBinaryTreeHelper(vector<int>& pre, int pre_start, int pre_end, vector<int>& vin, int vin_start, int vin_end)
    {
        if (pre_start > pre_end || vin_start > vin_end)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pre_start]);
        for (int i = vin_start; i <= vin_end; ++i)
        {
            if (pre[pre_start] == vin[i])
            {
                root->left = reConstructBinaryTreeHelper(pre, pre_start + 1, i - vin_start + pre_start, vin, vin_start, i - 1);
                root->right = reConstructBinaryTreeHelper(pre, i - vin_start + pre_start + 1, pre_end, vin, i + 1, vin_end);
                break;
            }
        }
        return root;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
            return nullptr;
        return reConstructBinaryTreeHelper(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};