#define _CRT_SECURE_NO_WARNINGS 1

//盛水最多的容器
//双指针
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            int cur = min(height[l], height[r]) * (r - l);
            ans = max(ans, cur);
            if (height[l] <= height[r])
                ++l;
            else
                --r;
        }
        return ans;
    }
};

//整数转罗马数字
class Solution {
public:
    string intToRoman(int num)
    {
        string ans;
        int m, c, x, i;
        m = num / 1000;
        num %= 1000;
        ans.append(m, 'M');
        //百位
        c = num / 100;
        num %= 100;
        if (c >= 5)
        {
            if (c == 9)
                ans += "CM";
            else
            {
                c %= 5;
                ans += "D";
                ans.append(c, 'C');
            }
        }
        else
        {
            if (c == 4)
                ans += "CD";
            else
                ans.append(c, 'C');
        }
        //十位
        x = num / 10;
        num %= 10;
        if (x >= 5)
        {
            if (x == 9)
                ans += "XC";
            else
            {
                x %= 5;
                ans += "L";
                ans.append(x, 'X');
            }
        }
        else
        {
            if (x == 4)
                ans += "XL";
            else
                ans.append(x, 'X');
        }
        //个位
        i = num / 1;
        if (i >= 5)
        {
            if (i == 9)
                ans += "IX";
            else
            {
                i %= 5;
                ans += "V";
                ans.append(i, 'I');
            }
        }
        else
        {
            if (i == 4)
                ans += "IV";
            else
                ans.append(i, 'I');
        }
        return ans;
    }
};