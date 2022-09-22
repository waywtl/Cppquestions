#define _CRT_SECURE_NO_WARNINGS 1

//完成所有交易的初始最少钱数
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t)
    {
        long long total_lose = 0;
        long long _max = 0;
        for (auto& v : t)
        {
            if (v[0] > v[1])
            {
                total_lose += (v[0] - v[1]);
                if (v[1] > _max)
                    _max = v[1];
            }
            else if (v[0] > _max)
            {
                _max = v[0];
            }
        }
        return total_lose + _max;
    }
};