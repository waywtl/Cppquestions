#define _CRT_SECURE_NO_WARNINGS 1

//重新排列单词间的空格
class Solution {
public:
    string reorderSpaces(string text)
    {
        int space_cnt = 0;
        int n = text.size();
        int i = 0, j = 0;
        vector<string> v;
        while (i < n && j < n)
        {
            if (text[i] == ' ' && text[j] == ' ')
            {
                ++i;
                ++j;
            }
            else if (text[j] != ' ')
                ++j;
            else if (text[i] != ' ' && text[j] == ' ')
            {
                v.push_back(text.substr(i, j - i));
                i = j;
            }
        }
        if (i <= n - 1)
            v.push_back(text.substr(i, j - i));

        int total = 0;
        for (auto& s : v)
            total += s.size();

        space_cnt = n - total;
        int m = v.size();
        int sep = (m == 1) ? 0 : space_cnt / (m - 1);
        int left = (m == 1) ? space_cnt : space_cnt % (m - 1);
        string ans;

        for (int i = 0; i < m; ++i)
        {
            ans += v[i];
            if (i == m - 1)
                break;

            for (int j = 0; j < sep; ++j)
                ans += " ";
        }
        while (left--)
            ans += " ";
        return ans;
    }
};

//至少是其他数字两倍的最大数
class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        int max_index = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > nums[max_index])
                max_index = i;
        }

        bool flag = true;
        for (auto& x : nums)
        {
            if (x != nums[max_index] && x * 2 > nums[max_index])
                flag = false;
        }

        return flag ? max_index : -1;
    }
};

//雪糕的最大数量
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (coins >= costs[i])
            {
                ++ans;
                coins -= costs[i];
            }
        }
        return ans;
    }
};