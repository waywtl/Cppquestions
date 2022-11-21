#define _CRT_SECURE_NO_WARNINGS 1

//2478. 完美分割的方案数
// 
//困难
//给你一个字符串 s ，每个字符是数字 '1' 到 '9' ，再给你两个整数 k 和 minLength 。
//
//如果对 s 的分割满足以下条件，那么我们认为它是一个 完美 分割：
//
//s 被分成 k 段互不相交的子字符串。
//每个子字符串长度都 至少 为 minLength 。
//每个子字符串的第一个字符都是一个 质数 数字，最后一个字符都是一个 非质数 数字。质数数字为 '2' ，'3' ，'5' 和 '7' ，剩下的都是非质数数字。
//请你返回 s 的 完美 分割数目。由于答案可能很大，请返回答案对 1e9 + 7 取余 后的结果。
//
//一个 子字符串 是字符串中一段连续字符串序列。
class Solution {
public:
    int MOD = 1e9 + 7;
    int beautifulPartitions(string s, int k, int l)
    {
        //f[i][j]  把s前j个分成i段的方案数
        //f[i][j] += f[i-1][j']

        //f[k][n]

        int n = s.size();
        auto is_prim = [&](char c) {return c == '2' || c == '3' || c == '5' || c == '7'; };

        auto is_partition = [&](int i) {return i == 0 || i == n || (is_prim(s[i]) && !is_prim(s[i - 1])); };

        if (!is_prim(s[0]) || is_prim(s[n - 1]) || k * l > n)
            return 0;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < k + 1; ++i)
        {
            int tot = 0;
            for (int j = i * l; j < n - (k - i) * l + 1; ++j)
            {
                if (is_partition(j - l))
                    tot = (tot + dp[i - 1][j - l]) % MOD;
                if (is_partition(j))
                    dp[i][j] = tot;
            }
        }
        return dp[k][n];
    }
};
