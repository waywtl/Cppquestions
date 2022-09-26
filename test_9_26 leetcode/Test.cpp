#define _CRT_SECURE_NO_WARNINGS 1

//好路径的数目
//思路：并查集
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
    {
        int n = vals.size();
        int ans = n;

        vector<vector<int>> g(n);
        for (auto& v : edges)
        {
            int x = v[0], y = v[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> ufs(n);
        vector<int> id(n);
        iota(ufs.begin(), ufs.end(), 0);
        iota(id.begin(), id.end(), 0);
        auto Find = [&](int x) {
            int fx = ufs[x];
            while (fx != x)
            {
                x = fx;
                fx = ufs[x];
            }

            return x;
        };

        vector<int> size(n, 1);
        sort(id.begin(), id.end(), [&](int x1, int x2) {return vals[x1] < vals[x2]; });

        for (auto& x : id)
        {
            int fx = Find(x);
            int vx = vals[x];
            for (auto& y : g[x])
            {
                int fy = Find(y);
                if (fx == fy || vals[y] > vx)
                    continue;
                if (vx == vals[fy])
                {
                    ans += (size[fx] * size[fy]);
                    size[fx] += size[fy];
                }
                ufs[fy] = fx;
            }
        }
        return ans;
    }
};

//消失的两个数字
//方法1：异或
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        int n = nums.size();
        n += 2;
        int _xor = 0;
        for (auto& num : nums)
            _xor ^= num;
        for (int i = 1; i < n + 1; ++i)
            _xor ^= i;

        int low = _xor & (-_xor);
        int x = 0;
        int y = 0;
        for (auto& num : nums)
        {
            if (num & low)
                x ^= num;
            else
                y ^= num;
        }

        for (int i = 1; i < n + 1; ++i)
        {
            if (i & low)
                x ^= i;
            else
                y ^= i;
        }
        return { x, y };
    }
};

//方法2：求和
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        int n = nums.size();
        n += 2;
        int sum = 0;
        for (auto& num : nums)
            sum += num;

        int ret_sum = n * (n + 1) / 2 - sum;
        int mid = ret_sum / 2;

        sum = 0;
        for (auto& num : nums)
        {
            if (num <= mid)
                sum += num;
        }
        int x = mid * (mid + 1) / 2 - sum;
        int y = ret_sum - x;
        return { x, y };
    }
};