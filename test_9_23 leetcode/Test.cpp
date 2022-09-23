#define _CRT_SECURE_NO_WARNINGS 1

//Éè¼ÆÁ´±í
class MyLinkedList {
public:
    struct ListNode
    {
        int _val;
        ListNode* _next;
        ListNode* _prev;

        ListNode(int val = 0)
            :_val(val)
            , _next(nullptr)
            , _prev(nullptr)
        {}
    };

    MyLinkedList() {
        ListNode* head = new ListNode();
        _head = head;

        _head->_prev = _head;
        _head->_next = _head;
        _size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= _size)
            return -1;

        ListNode* cur = _head->_next;
        while (index--)
        {
            cur = cur->_next;
        }
        return cur->_val;
    }

    void addAtHead(int val)
    {
        // ++_size;

        // ListNode* newNode = new ListNode(val);

        // ListNode* next = _head->_next;

        // _head->_next = newNode;
        // newNode->_prev = _head;

        // newNode->_next = next;
        // next->_prev = newNode;
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        ++_size;

        ListNode* newNode = new ListNode(val);

        ListNode* tail = _head->_prev;

        tail->_next = newNode;
        newNode->_prev = tail;

        newNode->_next = _head;
        _head->_prev = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index > _size)
            return;
        if (index < 0)
            index = 1;
        ListNode* newNode = new ListNode(val);

        ListNode* cur = _head->_next;
        while (index--)
        {
            cur = cur->_next;
        }

        ListNode* prev = cur->_prev;

        prev->_next = newNode;
        newNode->_prev = prev;

        newNode->_next = cur;
        cur->_prev = newNode;

        ++_size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= _size)
            return;
        ListNode* del = _head->_next;
        while (index--)
        {
            del = del->_next;
        }

        ListNode* prev = del->_prev;
        ListNode* next = del->_next;

        prev->_next = next;
        next->_prev = prev;

        --_size;
        delete del;
    }
private:
    ListNode* _head;
    int _size;
};