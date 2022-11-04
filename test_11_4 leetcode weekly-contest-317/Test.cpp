#define _CRT_SECURE_NO_WARNINGS 1

//可被三整除的偶数的平均值
class Solution {
public:
    int averageValue(vector<int>& nums)
    {
        int cnt = 0;
        int sum = 0;
        for (auto& x : nums)
        {
            if (x % 3 == 0 && x % 2 == 0)
            {
                ++cnt;
                sum += x;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};

//最流行的视频创作者
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int n = views.size();
        int max_view = 0;
        for (int i = 0; i < n; ++i)
        {
            string name = creators[i];
            if (m1.find(name) == m1.end() || views[i] > views[m1[name]] || (views[i] == views[m1[name]] && ids[i] < ids[m1[name]]))
            {
                m1[name] = i;
            }
            m2[name] += views[i];
            if (m2[name] > max_view)
                max_view = m2[name];
        }

        for (auto& p : m1)
        {
            if (m2[p.first] == max_view)
            {
                ans.push_back({ p.first, ids[p.second] });
            }
        }
        return ans;
    }
};

//美丽整数的最小增量
class Solution {
public:
    typedef long long ll;
    long long makeIntegerBeautiful(long long n, int target)
    {
        ll ans = 0;
        int sum = 0;
        ll tmp = n;
        while (tmp)
        {
            sum += (tmp % 10);
            tmp /= 10;
        }
        if (sum <= target)
            return 0;

        tmp = n;
        ll i = 1;
        while (sum > target)
        {
            sum = 0;
            i *= 10;
            ll cur = (tmp % i);
            tmp += (i - cur);
            ll ttmp = tmp;
            while (ttmp)
            {
                sum += (ttmp % 10);
                ttmp /= 10;
            }
        }
        return tmp - n;
    }
};