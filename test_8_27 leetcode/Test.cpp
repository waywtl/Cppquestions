#define _CRT_SECURE_NO_WARNINGS 1

//整数反转
class Solution {
public:
    int reverse(int x)
    {
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long num = stoll(s);
        if (num > INT_MAX)
            return 0;

        int ans = (int)num;
        if (x < 0)
            return -ans;
        return ans;
    }
};

//字符串转换整数(atoi)
class Solution {
public:
    int myAtoi(string s)
    {
        bool flag = true;
        bool start = false;
        bool start2 = false;
        bool start3 = false;
        long long num = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!start3 && !start2 && s[i] == ' ')
                continue;
            else
                start = true;

            if (!start3 && !start2 && s[i] == '-')
            {
                flag = false;
                start2 = true;
                continue;
            }
            else if (!start3 && !start2 && s[i] == '+')
            {
                start2 = true;
                continue;
            }

            if (start && (s[i] - '0' < 0 || s[i] - '0' > 9))
                break;

            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                start3 = true;
                num *= 10;
                num += s[i] - '0';
                if (!flag && -num <= INT_MIN)
                    return INT_MIN;
                if (flag && num >= INT_MAX)
                    return INT_MAX;
            }
        }
        if (flag)
            return (int)num;
        else
            return (int)-num;
    }
};