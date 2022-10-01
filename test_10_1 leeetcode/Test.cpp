#define _CRT_SECURE_NO_WARNINGS 1

//重新格式化电话号码
class Solution {
public:
    string reformatNumber(string number)
    {
        string sub;
        string ans;
        for (auto& ch : number)
        {
            if (ch == '-' || ch == ' ')
                continue;

            sub += ch;
            if (sub.size() == 3)
            {
                ans += sub;
                ans += "-";
                sub = "";
            }
        }

        if (sub.size() == 0)
        {
            ans.pop_back();
        }
        else if (sub.size() == 1)
        {
            char ch = ans[ans.size() - 2];
            ans.pop_back();
            ans.pop_back();
            ans += "-";
            ans += ch;
            ans += sub;
        }
        else if (sub.size() == 2)
        {
            ans += sub;
        }
        return ans;
    }
};