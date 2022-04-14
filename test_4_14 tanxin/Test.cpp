#define _CRT_SECURE_NO_WARNINGS 1

//多机调度问题
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solutions
{
public:
	int TaskAssignments(int taskCnt, vector<int>& times, int machineCnt)
	{
		sort(times.begin(), times.end());
		reverse(times.begin(), times.end());
		if (taskCnt <= machineCnt)
			return times[0];
		vector<int> v;
		v.resize(machineCnt, 0);
		for (int i = 0; i < taskCnt; ++i)
		{
			int index = 0;
			for (int j = 0; j < machineCnt; ++j)
			{
				if (v[j] < v[index])
					index = j;
			}
			v[index] += times[i];
		}
		int ret = 0;
		for (int i = 0; i < machineCnt; ++i)
		{
			ret = max(v[i], ret);
		}
		return ret;
	}
};

//活动选择
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] < v2[1];
}

class Solutionss
{
public:
	int MaxActives(vector<vector<int>> times)
	{
		sort(times.begin(), times.end(), cmp);
		int cnt = 1;
		int endTime = times[0][1];
		for (int i = 1; i < times.size(); ++i)
		{
			if (times[i][0] >= endTime)
			{
				++cnt;
				endTime = times[i][1];
			}
		}
		return cnt;
	}
};

//最多可以参加的会议数目
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	return v1[0] < v2[0];
}

class Solution {
public:
	int maxEvents(vector<vector<int>>& events)
	{
		sort(events.begin(), events.end(), cmp);
		priority_queue<int, vector<int>, greater<int>> pq;

		int curDay = 1;
		int i = 0;
		int cnt = 0;
		while (i < events.size() || !pq.empty())
		{
			while (i < events.size() && events[i][0] == curDay)
			{
				pq.push(events[i][1]);
				++i;
			}

			while (!pq.empty() && pq.top() < curDay)
				pq.pop();

			if (!pq.empty())
			{
				pq.pop();
				++cnt;
			}
			++curDay;
		}
		return cnt;
	}
};

//无重叠区间
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	return v1[0] < v2[0];
}

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		if (intervals.size() == 0)
			return 0;

		sort(intervals.begin(), intervals.end(), cmp);
		int prev = 0;
		int cnt = 0;
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[prev][1] > intervals[i][0])
			{
				if (intervals[prev][1] > intervals[i][1])
					prev = i;
				++cnt;
			}
			else
				prev = i;
		}
		return cnt;
	}
};