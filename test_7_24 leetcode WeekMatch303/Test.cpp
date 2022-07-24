#define _CRT_SECURE_NO_WARNINGS 1

//第一个出现两次的字母
class Solution {
public:
    char repeatedCharacter(string s)
    {
        char ans = 0;
        int arr[200] = { 0 };
        for (int i = 0; i < s.size(); ++i)
        {
            ++arr[s[i]];
            if (arr[s[i]] == 2)
                return s[i];
        }
        return 0;
    }
};

//相等行列对
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int ans = 0;
        int flag = 1;
        for (vector<int>& v : grid)
        {
            for (int i = 0; i < n; ++i)
            {
                flag = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (grid[j][i] != v[j])
                    {
                        flag = 0;
                        continue;
                    }
                }
                if (flag == 1)
                    ++ans;
            }
        }
        return ans;
    }
};

//设计食物评分系统
class FoodRatings {
public:
    typedef pair<int, string> pis;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        for (int i = 0; i < foods.size(); ++i)
        {
            mp1[foods[i]] = pis(ratings[i], cuisines[i]);
            mp2[cuisines[i]].insert(pis(-ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating)
    {
        pis& p = mp1[food];
        mp2[p.second].erase(pis(-p.first, food));
        p.first = newRating;
        mp2[p.second].insert(pis(-p.first, food));
    }

    string highestRated(string cuisine)
    {
        return mp2[cuisine].begin()->second;
    }
private:
    unordered_map<string, pis> mp1;
    unordered_map<string, set<pis>> mp2;
};

//优质数对的数目
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k)
    {
        long long ans = 0;
        set<int> s;
        for (int i = 0; i < nums.size(); ++i)
            s.insert(nums[i]);
        vector<int> v(31, 0);
        for (int x : s)
        {
            int cnt = 0;
            while (x)
            {
                x &= (x - 1);
                ++cnt;
            }
            ++v[cnt];
        }
        for (int i = 0; i < 31; ++i)
        {
            for (int j = 0; j < 31; ++j)
            {
                if (i + j >= k)
                    ans += v[i] * v[j];
            }
        }
        return ans;
    }
};