#define _CRT_SECURE_NO_WARNINGS 1

//统计共同度过的日子
class Solution {
public:
    int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        if (leaveAlice < arriveBob)
            return 0;
        if (leaveBob < arriveAlice)
            return 0;
        int ans = 1;
        string max_m = max(arriveAlice, arriveBob);
        int month1 = stoi(max_m.substr(0, 2));
        int day1 = stoi(max_m.substr(3, 2));

        string min_m = min(leaveAlice, leaveBob);
        int month2 = stoi(min_m.substr(0, 2));
        int day2 = stoi(min_m.substr(3, 2));

        while (month1 < month2)
        {
            ++day1;
            ++ans;
            if (day1 > a[month1])
            {
                day1 = 1;
                ++month1;
            }
        }

        return ans + day2 - day1;
    }
};

//运动员和训练师的最大匹配数
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        int n = players.size();
        int m = trainers.size();
        for (int i = 0, j = 0; i < n && j < m;)
        {
            if (trainers[j] < players[i])
                ++j;
            else
            {
                ++i;
                ++j;
                ++ans;
            }
        }
        return ans;
    }
};

//按位或最大的最小子数组长度
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i)
        {
            ans[i] = 1;
            for (int j = i - 1; j >= 0 && (nums[j] | nums[i]) > nums[j]; --j)
            {
                nums[j] |= nums[i];
                ans[j] = i - j + 1;
            }
        }
        return ans;
    }
};