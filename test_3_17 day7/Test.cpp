#define _CRT_SECURE_NO_WARNINGS 1

//字符串全排列
class Solution {
public:
    void PermutationHelper(vector<string>& ret, string tmp, string s)
    {
        if (tmp.empty())
        {
            ret.push_back(s);
            return;
        }
        for (int i = 0; i < tmp.size(); ++i)
        {
            string ttmp = tmp;
            ttmp.erase(i, 1);
            PermutationHelper(ret, ttmp, s + tmp[i]);
        }
    }

    vector<string> Permutation(string str)
    {
        vector<string> ret;
        if (str.empty())
            return ret;
        string s;
        string tmp = str;
        PermutationHelper(ret, tmp, s);
        for (size_t i = 0; i < ret.size(); ++i)
        {
            for (size_t j = i + 1; j < ret.size(); ++j)
            {
                if (ret[j] == ret[i])
                {
                    auto pos = find(ret.begin() + j, ret.end(), ret[j]);
                    ret.erase(pos);
                    --j;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    void swap(string& str, int start, int end)
    {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
    }

    bool IsExist(string& str, vector<string> ret)
    {
        auto it = ret.begin();
        while (it != ret.end())
        {
            if (*it == str)
            {
                return true;
            }
            ++it;
        }
        return false;
    }

    void PermutationHepler(string& str, int start, vector<string>& ret)
    {
        if (start == str.size() - 1)
        {
            if (!IsExist(str, ret))
            {
                ret.push_back(str);
            }
            return;
        }

        for (int i = start; i < str.size(); ++i)
        {
            swap(str, start, i);
            PermutationHepler(str, start + 1, ret);
            swap(str, start, i);
        }
    }

    vector<string> Permutation(string str)
    {
        vector<string> ret;
        if (str.size() > 0)
        {
            PermutationHepler(str, 0, ret);
        }
        return ret;
    }
};


//topK问题
class Solution {
public:
    struct comp
    {
        bool operator()(const int& a, const int& b)
        {
            return a < b;
        }
    };

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> ret;
        if (input.size() == 0 || k <= 0 || input.size() < k)
        {
            return ret;
        }
        priority_queue<int, vector<int>, comp> queue;
        for (int i = 0; i < input.size(); ++i)
        {
            if (i < k)
            {
                queue.push(input[i]);
            }
            else
            {
                if (input[i] < queue.top())
                {
                    queue.pop();
                    queue.push(input[i]);
                }
            }
        }
        for (int i = 0; i < k; ++i)
        {
            ret.push_back(queue.top());
            queue.pop();
        }
        return ret;
    }
};

//连续子数组最大和
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        vector<int> dp(array.size() + 1, 0);
        int ret = array[0];
        dp[0] = array[0];
        for (int i = 1; i < array.size() + 1; ++i)
        {
            dp[i] = max(array[i], dp[i - 1] + array[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};