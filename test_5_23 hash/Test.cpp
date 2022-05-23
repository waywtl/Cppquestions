#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


//两句话中不常见的单词
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;
        vector<string> ret;
        int start = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == ' ')
            {
                string str = s1.substr(start, i - start);
                map1[str]++;
                start = i + 1;
            }
        }
        string str = s1.substr(start, s1.size() - start);
        map1[str]++;

        start = 0;
        for (int i = 0; i < s2.size(); ++i)
        {
            if (s2[i] == ' ')
            {
                string str = s2.substr(start, i - start);
                map2[str]++;
                start = i + 1;
            }
        }
        str = s2.substr(start, s2.size() - start);
        map2[str]++;

        for (auto& e : map1)
        {
            if (map1[e.first] == 1 && !map2.count(e.first))
            {
                ret.push_back(e.first);
            }
        }

        for (auto& e : map2)
        {
            if (map2[e.first] == 1 && !map1.count(e.first))
            {
                ret.push_back(e.first);
            }
        }
        return ret;
    }
};

//存在重复元素
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m[nums[i]] == 1)
                return true;
            m[nums[i]]++;
        }
        return false;
    }
};

//两个数的交集
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> ret;
        for (int i = 0; i < nums1.size(); ++i)
        {
            s1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            s2.insert(nums2[i]);
        }
        for (auto& e : s1)
        {
            if (s2.find(e) != s2.end())
                ret.push_back(e);
        }
        return ret;
    }
};

//两个数组的交集Ⅱ
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        vector<int> ret;
        for (int i = 0; i < nums1.size(); ++i)
        {
            m1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            m2[nums2[i]]++;
        }
        for (auto& e : m1)
        {
            if (m2.find(e.first) != m2.end())
            {
                int cnt = min(m1[e.first], m2[e.first]);
                ret.insert(ret.end(), cnt, e.first);
            }
        }
        return ret;
    }
};

//在长度2N的数组中找出重复N次的元素
class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]]++;
        }
        for (auto& e : m)
        {
            if (m[e.first] == nums.size() / 2)
                return e.first;
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        return nums[mid] == nums[mid + 1] ? nums[mid] : nums[mid - 1];
    }
};