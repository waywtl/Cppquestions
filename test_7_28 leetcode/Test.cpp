#define _CRT_SECURE_NO_WARNINGS 1

//LRU»º´æ
class LRUCache {
public:
    struct ListNode
    {
        ListNode* prev;
        ListNode* next;
        int _key;
        int _val;

        ListNode()
            :prev(nullptr)
            , next(nullptr)
            , _key(0)
            , _val(0)
        {}
    };

    unordered_map<int, ListNode*> m;
    ListNode* head;
    ListNode* tail;
    int _size;
    int _capacity;

    LRUCache(int capacity)
        :_capacity(capacity)
        , _size(0)
    {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            MoveToHead(m[key]);
            return m[key]->_val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key]->_val = value;
            MoveToHead(m[key]);
            return;
        }
        ListNode* newNode = new ListNode();
        newNode->_key = key;
        newNode->_val = value;
        if (_size == _capacity)
        {
            ListNode* Tail = EraseOnTail();
            int Tail_key = Tail->_key;
            m.erase(m.find(Tail_key));
            --_size;
        }
        m[key] = newNode;
        AddToHead(newNode);
        ++_size;
    }

    void AddToHead(ListNode* pNode)
    {
        ListNode* Next = head->next;
        head->next = pNode;
        pNode->prev = head;

        pNode->next = Next;
        Next->prev = pNode;
    }

    ListNode* EraseOnTail()
    {
        ListNode* Tail = tail->prev;
        RemoveNode(Tail);

        return Tail;
    }

    void RemoveNode(ListNode* pNode)
    {
        pNode->prev->next = pNode->next;
        pNode->next->prev = pNode->prev;
    }

    void MoveToHead(ListNode* pNode)
    {
        RemoveNode(pNode);
        AddToHead(pNode);
    }
};

//ÅÅÐòÁ´±í
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* head = new ListNode();
        head->next = nullptr;
        ListNode* cur = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr)
            cur->next = l2;
        else
            cur->next = l1;
        return head->next;
    }

    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        return merge(sortList(slow), sortList(fast));
    }
};