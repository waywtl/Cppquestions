#define _CRT_SECURE_NO_WARNINGS 1

//链表合并，递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
        {
            return pHead2;
        }
        if (pHead2 == nullptr)
        {
            return pHead1;
        }
        ListNode* head = nullptr;
        if (pHead1->val > pHead2->val)
        {
            head = pHead2;
            pHead2 = pHead2->next;
        }
        else
        {
            head = pHead1;
            pHead1 = pHead1->next;
        }
        head->next = Merge(pHead1, pHead2);
        return head;
    }
};

//树的子结构
class Solution {
public:
    bool HasSubtreeHelp(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)
        {
            return true;
        }
        if (pRoot1 == nullptr)
        {
            return false;
        }
        if (pRoot1->val != pRoot2->val)
        {
            return false;
        }
        return HasSubtreeHelp(pRoot1->left, pRoot2->left) && HasSubtreeHelp(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
        {
            return false;
        }
        if (pRoot1->val == pRoot2->val)
        {
            if (HasSubtreeHelp(pRoot1, pRoot2))
                return true;
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};

//删除链表中重复的结点
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode* head = new ListNode(0);
        head->next = pHead;

        ListNode* front = head->next;
        ListNode* rear = head;
        while (front != nullptr)
        {
            while (front->val != front->next->val && front->next != nullptr)
            {
                front = front->next;
                rear = rear->next;
            }
            while (front->val == front->next->val && front->next != nullptr)
            {
                front = front->next;
            }
            if (rear->next != front)
                rear->next = front->next;
            front = front->next;
        }
        return head->next;
    }
};