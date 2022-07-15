#define _CRT_SECURE_NO_WARNINGS 1

//24点游戏
class Solution {
public:
    double epsilon = 1e-6;
    bool Helper(vector<double>& vd)
    {
        int size = vd.size();
        //if (size == 1 && vd[0] == 24)
        if (size == 1 && abs(vd[0] - 24) <= epsilon)
            return true;
        if (size == 0)
            return false;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (i != j)
                {
                    vector<double> new_vd;
                    for (int k = 0; k < size; ++k)
                    {
                        if (k != i && k != j)
                        {
                            new_vd.push_back(vd[k]);
                        }
                    }
                    for (int op = 0; op < 4; ++op)
                    {
                        if ((op == 0 || op == 2) && i > j)
                            continue;
                        if (op == 0)
                        {
                            new_vd.push_back(vd[i] + vd[j]);
                        }
                        else if (op == 1)
                        {
                            new_vd.push_back(vd[i] - vd[j]);
                        }
                        else if (op == 2)
                        {
                            new_vd.push_back(vd[i] * vd[j]);
                        }
                        else if (op == 3)
                        {
                            if (vd[j] == 0)
                                continue;
                            new_vd.push_back(vd[i] / vd[j]);
                        }
                        if (Helper(new_vd))
                            return true;
                        new_vd.pop_back();
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards)
    {
        vector<double> vd;
        for (int i = 0; i < cards.size(); ++i)
        {
            vd.push_back(static_cast<double>(cards[i]));
        }
        return Helper(vd);
    }
};

//合并区间
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		int n = intervals.size();
		vector<int> v = intervals[0];
		for (int i = 1; i < n; ++i)
		{
			if (intervals[i][0] <= v[1])
			{
				int max_val = max(v[1], intervals[i][1]);
				v[1] = max_val;
			}
			else
			{
				ans.push_back(v);
				v = intervals[i];
			}
		}
		ans.push_back(v);
		return ans;
	}
};