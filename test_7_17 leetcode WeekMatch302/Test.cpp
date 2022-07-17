#define _CRT_SECURE_NO_WARNINGS 1

//1.数组能形成多少数对
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (auto e : nums)
            ++m[e];
        int a = 0;
        int b = 0;
        for (auto e : m)
        {

            a += e.second / 2;
            b += e.second % 2;
        }
        return { a, b };
    }
};

//2.数位和相等数对的最大和
class Solution {
public:
    int maximumSum(vector<int>& nums)
    {
        int ans = -1;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int sum = 0;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }
            if (!m[sum])
                m[sum] = nums[i];
            else
            {
                ans = max(ans, m[sum] + nums[i]);
                if (nums[i] > m[sum])
                    m[sum] = nums[i];
            }
        }
        return ans;
    }
};


//3.裁剪数字后查询第 K 小的数字
class Solution {
public:
    vector<string> helper1(vector<string>& nums, int num)
    {
        vector<string> v;
        int n = nums[0].size();
        for (int i = 0; i < nums.size(); ++i)
        {
            v.push_back(nums[i].substr(n - num));
        }
        return v;
    }

    int helper2(vector<string>& v, int k)
    {
        vector<pair<string, int>> vp;
        for (int i = 0; i < v.size(); ++i)
        {
            vp.push_back(make_pair(v[i], i));
        }
        sort(vp.begin(), vp.end());
        return vp[k - 1].second;
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
        {
            vector<string> v = helper1(nums, queries[i][1]);
            int ret = helper2(v, queries[i][0]);
            ans.push_back(ret);
        }
        return ans;
    }
};

//4.使数组可以被整除的最少删除次数
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < nums.size(); )
        {
            int flag = 0;
            for (int j = 0; j < numsDivide.size(); ++j)
            {
                if (numsDivide[j] % nums[i] != 0)
                {
                    ++i;
                    ++ans;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                while (nums[i - 1] == nums[i])
                {
                    ++i;
                    ++ans;
                }
            }
            else
            {
                return ans;
            }
        }
        return -1;
    }
};