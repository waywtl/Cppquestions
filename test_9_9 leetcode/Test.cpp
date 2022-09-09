#define _CRT_SECURE_NO_WARNINGS 1

//文件夹操作日志搜集器
class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int step = 0;
        for (auto& s : logs)
        {
            if (s.size() == 3 && s[0] == '.' && s[1] == '.')
                step = (step == 0) ? 0 : step - 1;
            else if (s.size() == 2 && s[0] == '.')
                continue;
            else
                ++step;
        }
        return step;
    }
};

//用 Rand7() 实现 Rand10()
class Solution {
public:
    int rand10()
    {
        int a = 0;
        int b = 0;
        int num = 0;
        while (true)
        {
            a = rand7();
            b = rand7();
            num = (a - 1) * 7 + b;//rand 49
            if (num <= 40)
                return num % 10 + 1;

            a = num - 40;//rand 9
            b = rand7();
            num = (a - 1) * 7 + b;//rand 63
            if (num <= 60)
                return num % 10 + 1;

            a = num - 60;//rand 3
            b = rand7();
            num = (a - 1) * 7 + b;//rand 21
            if (num <= 20)
                return num % 10 + 1;
        }
    }
};