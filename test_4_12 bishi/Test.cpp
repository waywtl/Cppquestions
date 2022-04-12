#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bag;
int cnt;
int n;

void dfs(int pos, int sum, int mul)
{
	for (int i = pos; i < n; ++i)
	{
		sum += bag[i];
		mul *= bag[i];
		if (sum > mul)
		{
			++cnt;
			dfs(i + 1, sum, mul);
		}
		else if (bag[i] == 1)
			dfs(i + 1, sum, mul);
		else
			break;
		sum -= bag[i];
		mul /= bag[i];
		while (i < n - 1 && bag[i] == bag[i + 1])
			++i;
	}
}

int main()
{
	cin >> n;
	bag.resize(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> bag[i];
	sort(bag.begin(), bag.end());
	dfs(0, 0, 1);
	cout << cnt << endl;
	return 0;
}