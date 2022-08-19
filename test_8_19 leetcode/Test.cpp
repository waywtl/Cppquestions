#define _CRT_SECURE_NO_WARNINGS 1

//比特位计数
//方法1：常规做法，直接计算每个数的比特位为1的个数 O(nlogn)
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;
            int num = i;
            while (num)
            {
                num &= (num - 1);
                ++cnt;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

//方法二：动态规划，分奇偶判断 O(n)
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            /*if (i % 2)
                ans[i] = ans[i - 1] + 1;
            else
                ans[i] = ans[i / 2];*/
            ans[i] = ans[i >> 1] + (i & 1);//一行搞定
        }
        return ans;
    }
};

//方法3：动态规划，利用 (x & (x-1)) 比 x 少一个1  O(n)
class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};

//前K个高频元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto& num : nums)
        {
            ++m[num];
        }

        for (auto& p : m)
        {
            q.push({ p.second, p.first });
        }

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};

//字符串解码
//方法1：递归
class Solution {
public:
    string decodeString(string s)
    {
        int len = s.size();
        //从右边开始找第一个 '['
        int i = len - 1;
        while (i > 0 && s[i] != '[')
            --i;
        if (i == 0)
            return s;
        //找[]前面的数字
        int j = i - 1;
        while (j >= 0 && (s[j] - '0' < 10))
            --j;
        int cnt = stoi(s.substr(j + 1, i - j + 1));

        //找与'['匹配的']'
        int k = i + 1;
        while (k < len && s[k] != ']')
            ++k;

        //拿到需要复制的部分
        string cp = s.substr(i + 1, k - i - 1);
        string mid = cp;
        while (--cnt)
            mid += cp;
        //拿头
        string head = s.substr(0, j + 1);
        //拿尾
        string tail = (k == len - 1) ? "" : s.substr(k + 1);
        //拼接，此时，已经解决了一个[]
        string str = head + mid + tail;
        //递归解决子问题
        return decodeString(str);
    }
};

//方法2：数字栈+字符串栈
class Solution {
public:
    string decodeString(string s)
    {
        int len = s.size();
        stack<int> stn;
        stack<string> sts;
        int num = 0;
        string str = "";
        for (int i = 0; i < len; ++i)
        {
            if (s[i] - '0' < 10)
                num = num * 10 + s[i] - '0';
            else if (s[i] >= 'a' && s[i] <= 'z')
                str += s[i];
            else if (s[i] == '[')
            {
                stn.push(num);
                num = 0;
                sts.push(str);
                str = "";
            }
            else if (s[i] == ']')
            {
                int cnt = stn.top();
                stn.pop();
                while (cnt--)
                    sts.top() += str;
                str = sts.top();
                sts.pop();
            }
        }
        return str;
    }
};