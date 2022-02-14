#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//动态规划  3+1
//1.定义状态
//2.递推方程
//3.初始化
//加一个数组

//矩形覆盖
class Solution {
public:
    int rectCover(int number)
    {
        if (number == 0)
            return 0;
        int* dp = new int[number + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int result = dp[number];
        delete[]dp;
        return result;
    }
};

//二进制中1的个数
class Solution {
public:
    int  NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

//链表中倒数第k个节点
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if (pListHead == nullptr)
            return nullptr;
        ListNode* front = pListHead;
        ListNode* rear = pListHead;
        while (k > 0 && front)
        {
            front = front->next;
            k--;
        }
        while (front)
        {
            front = front->next;
            rear = rear->next;
        }
        return k > 0 ? nullptr : rear;
    }
};