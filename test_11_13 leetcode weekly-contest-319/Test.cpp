#define _CRT_SECURE_NO_WARNINGS 1

//温度转换
class Solution {
public:
    vector<double> convertTemperature(double celsius)
    {
        return { celsius + 273.15, celsius * 1.8 + 32 };
    }
};

//最小公倍数为 K 的子数组数目
class Solution {
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int subarrayLCM(vector<int>& nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int x = 1;
            for (int j = i; j < n; ++j)
            {
                x = x * nums[j] / gcd(nums[j], x);
                if (x == k)
                    ++ans;
                if (x > k)
                    break;
            }
        }
        return ans;
    }
};

//逐层排序二叉树所需的最少操作数目
class Solution {
public:
    int minimumOperations(TreeNode* root)
    {
        int ans = 0;
        vector<int> a;
        vector<TreeNode*> p;
        p.push_back(root);
        while (p.size() != 0)
        {
            a = {};
            vector<TreeNode*> tmp = p;
            p = {};

            for (auto& node : tmp)
            {
                a.push_back(node->val);
                if (node->left)
                    p.push_back(node->left);
                if (node->right)
                    p.push_back(node->right);
            }

            int n = a.size();
            vector<int> b = a;
            sort(b.begin(), b.end());

            unordered_map<int, pair<int, bool>> m;
            for (int i = 0; i < n; ++i)
                m[a[i]] = { b[i], false };

            ans += n;
            for (auto& _p : m)
            {
                if (_p.second.second)
                    continue;
                _p.second.second = true;
                int target = _p.second.first;
                while (!m[target].second)
                {
                    m[target].second = true;
                    target = m[target].first;
                }
                ans -= 1;
            }
        }
        return ans;
    }
};

//不重叠回文子字符串的最大数目
class Solution {
public:
    vector<vector<bool>> GetMat(const string& s)
    {
        int len = s.size();
        vector<vector<bool>> mat(len, vector<bool>(len, false));
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i; j < len; ++j)
            {
                if (i == j)
                    mat[i][j] = true;
                else if (j == i + 1)
                    mat[i][j] = (s[i] == s[j]);
                else
                    mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
            }
        }
        return mat;
    }

    int maxPalindromes(string s, int k)
    {
        int len = s.size();
        vector<int> dp(len + 1, 0);

        vector<vector<bool>> mat = GetMat(s);

        for (int i = 1; i <= len; ++i)
        {
            dp[i] = dp[i - 1];
            for (int j = i - 1; j >= 0; --j)
            {
                if (mat[j][i - 1] && i - j >= k)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[len];
    }
};