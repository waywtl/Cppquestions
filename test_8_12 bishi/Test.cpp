#define _CRT_SECURE_NO_WARNINGS 1

//数组中出现次数超过一般的数字
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int ans = numbers[0];
        int n = numbers.size();
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (numbers[i] == ans)
                ++cnt;
            else
                --cnt;
            if (cnt == 0)
            {
                ans = numbers[i];
                cnt = 1;
            }
        }
        return ans;
    }
};

//简单错误记录
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "";
    int num = 0;
    vector<pair<string, int>> in_data;
    while (cin >> s >> num)
    {
        in_data.push_back({ s, num });
        while (cin >> s >> num)
            in_data.push_back({ s, num });

        unordered_map<string, int> m;
        queue<string> q;
        for (auto& p : in_data)
        {
            string str = p.first.substr(p.first.rfind('\\') + 1);
            int size = str.size();
            if (size > 16)
                str = str.substr(size - 16);
            int cnt = p.second;
            string ss = str + " " + to_string(cnt);

            ++m[ss];

            if (m[ss] < 2)
                q.push(ss);
            if (q.size() > 8)
                q.pop();
        }

        while (!q.empty())
        {
            string top = q.front();
            q.pop();
            cout << top << " " << m[top] << endl;
        }
    }
    return 0;
}