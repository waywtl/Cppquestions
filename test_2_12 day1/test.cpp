#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//二维数组中的查找
class Solution {
public:
    bool Find(int target, vector<vector<int> > array)
    {
        int i = 0;
        int j = array[0].size() - 1;
        while (i < array.size() && j >= 0)
        {
            if (target > array[i][j])
            {
                ++i;
            }
            else if (target < array[i][j])
            {
                --j;
            }
            else
                return true;
        }
        return false;
    }
};

//旋转数组的最小数字
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.empty())
            return 0;
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (left < right)
        {
            if (right - left == 1)
            {
                break;
            }
            mid = (left + right) >> 1;
            if (rotateArray[left] == rotateArray[mid] && rotateArray[left] == rotateArray[right])
            {
                int min = 0;
                for (int i = 0; i < rotateArray.size(); ++i)
                {
                    if (rotateArray[i] < rotateArray[min])
                    {
                        min = i;
                    }
                }
                right = min;
                break;
            }
            if (left < right && rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return rotateArray[right];
    }
};

//调整数组顺序使奇数位于偶数前面
class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        if (array.empty())
            return;
        int front = 0;
        int back = 0;
        while (front < array.size())
        {
            if (array[front] & 1)
            {
                int tmp = array[front];
                int k = front;
                while (k > back)
                {
                    array[k] = array[k - 1];
                    --k;
                }
                array[back++] = tmp;
                ++front;
            }
            else
            {
                ++front;
            }
        }
    }
};

//数组中出现次数超过一半的数字
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if (numbers.empty())
            return 0;
        int number = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (times == 0)
            {
                number = numbers[i];
            }
            if (number != numbers[i])
                --times;
            else
                ++times;
        }
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == number)
                ++count;
        }
        return count > numbers.size() / 2 ? number : 0;
    }
};