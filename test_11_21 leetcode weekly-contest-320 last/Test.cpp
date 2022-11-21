#define _CRT_SECURE_NO_WARNINGS 1

//2478. �����ָ�ķ�����
// 
//����
//����һ���ַ��� s ��ÿ���ַ������� '1' �� '9' ���ٸ����������� k �� minLength ��
//
//����� s �ķָ�����������������ô������Ϊ����һ�� ���� �ָ
//
//s ���ֳ� k �λ����ཻ�����ַ�����
//ÿ�����ַ������ȶ� ���� Ϊ minLength ��
//ÿ�����ַ����ĵ�һ���ַ�����һ�� ���� ���֣����һ���ַ�����һ�� ������ ���֡���������Ϊ '2' ��'3' ��'5' �� '7' ��ʣ�µĶ��Ƿ��������֡�
//���㷵�� s �� ���� �ָ���Ŀ�����ڴ𰸿��ܴܺ��뷵�ش𰸶� 1e9 + 7 ȡ�� ��Ľ����
//
//һ�� ���ַ��� ���ַ�����һ�������ַ������С�
class Solution {
public:
    int MOD = 1e9 + 7;
    int beautifulPartitions(string s, int k, int l)
    {
        //f[i][j]  ��sǰj���ֳ�i�εķ�����
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
