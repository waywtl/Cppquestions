#define _CRT_SECURE_NO_WARNINGS 1

//����λ����
//����1������������ֱ�Ӽ���ÿ�����ı���λΪ1�ĸ��� O(nlogn)
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

//����������̬�滮������ż�ж� O(n)
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
            ans[i] = ans[i >> 1] + (i & 1);//һ�и㶨
        }
        return ans;
    }
};

//����3����̬�滮������ (x & (x-1)) �� x ��һ��1  O(n)
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

//ǰK����ƵԪ��
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

//�ַ�������
//����1���ݹ�
class Solution {
public:
    string decodeString(string s)
    {
        int len = s.size();
        //���ұ߿�ʼ�ҵ�һ�� '['
        int i = len - 1;
        while (i > 0 && s[i] != '[')
            --i;
        if (i == 0)
            return s;
        //��[]ǰ�������
        int j = i - 1;
        while (j >= 0 && (s[j] - '0' < 10))
            --j;
        int cnt = stoi(s.substr(j + 1, i - j + 1));

        //����'['ƥ���']'
        int k = i + 1;
        while (k < len && s[k] != ']')
            ++k;

        //�õ���Ҫ���ƵĲ���
        string cp = s.substr(i + 1, k - i - 1);
        string mid = cp;
        while (--cnt)
            mid += cp;
        //��ͷ
        string head = s.substr(0, j + 1);
        //��β
        string tail = (k == len - 1) ? "" : s.substr(k + 1);
        //ƴ�ӣ���ʱ���Ѿ������һ��[]
        string str = head + mid + tail;
        //�ݹ���������
        return decodeString(str);
    }
};

//����2������ջ+�ַ���ջ
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