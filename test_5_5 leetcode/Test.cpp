#define _CRT_SECURE_NO_WARNINGS 1

//无重复字符的最长子串 ---- 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> book;
        int ret = 0;
        int end = 0;
        int start = 0;
        int size = s.size();
        while (start < size)
        {
            while (end < size && !book.count(s[end]))
            {
                book.insert(s[end]);
                ++end;
            }
            ret = max(ret, end - start);

            book.erase(s[start]);
            ++start;
        }
        return ret;
    }
};

//寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int LMax1, LMax2, RMin1, RMin2;
        int left = 0;
        int right = n;
        int median1 = 0;
        int median2 = 0;
        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = (n + m + 1) / 2 - i;

            int LMax1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int RMin1 = (i == n) ? INT_MAX : nums1[i];
            int LMax2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int RMin2 = (j == m) ? INT_MAX : nums2[j];

            if (LMax1 <= RMin2)
            {
                median1 = max(LMax1, LMax2);
                median2 = min(RMin1, RMin2);
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};

//最长回文子串
//方法1
//区间判定
class Solution {
public:
    vector<vector<bool>> GetBook(string s)
    {
        int len = s.size();
        vector<vector<bool>> book(len, vector<bool>(len, false));

        for(int i = len-1; i >= 0; --i)
        {
            for(int j = i; j < len; ++j)
            {
                if(i == j)
                    book[i][j] = true;
                else if(j == i+1)
                    book[i][j] = (s[i] == s[j]);
                else
                    book[i][j] = ((s[i] == s[j]) && book[i+1][j-1]);
            }
        }
        return book;
    }

    string longestPalindrome(string s)
    {
        string ret;
        if(s.size() == 0)
            return  ret;
        vector<vector<bool>> book = GetBook(s);
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            for(int j = i; j < size; ++j)
            {
                if(book[i][j])
                {
                    int len = j - i + 1;
                    if(len > ret.size())
                        ret = s.substr(i, len);
                }
            }
        }
        return ret;
    }
};

//方法2
//中心扩散 ---- 更优
class Solution { 
public:
    pair<int, int> Palindrome(const string& s, int i, int j)
    {
        int left = i;
        int right = j;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        pair<int, int> retP = make_pair(left + 1, right - 1);
        return retP;
    }

    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            pair<int, int> p1 = Palindrome(s, i, i);
            pair<int, int> p2 = Palindrome(s, i, i + 1);

            if (p1.second - p1.first > end - start)
            {
                start = p1.first;
                end = p1.second;
            }

            if (p2.second - p2.first > end - start)
            {
                start = p2.first;
                end = p2.second;
            }
        }
        string ret = s.substr(start, end - start + 1);
        return ret;
    }
};