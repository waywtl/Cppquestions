#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//最小相似数
int main()
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	//计算x,y的位数
	int xdigit = 1;
	int ydigit = 1;
	int a = x;
	int b = y;
	while (a)
	{
		if (a /= 10)
			xdigit++;
	}
	while (b)
	{
		if (b /= 10)
			ydigit++;
	}
	if (xdigit != ydigit)
	{
		printf("NO\n");
		return 0;
	}
	//将x,y的每一位放入相应的数组
	int sz = xdigit;
	int* xarr = (int*)malloc(sizeof(int) * sz);
	int* yarr = (int*)malloc(sizeof(int) * sz);
	int i = 0;
	int tmp = 0;
	for (tmp = x; tmp != 0; tmp /= 10)
	{
		xarr[i++] = tmp % 10;
	}
	i = 0;
	for (tmp = y; tmp != 0; tmp /= 10)
	{
		yarr[i++] = tmp % 10;
	}
	//如果y的前导为0
	if (yarr[sz - 1] == 0)
	{
		printf("NO\n");
		free(xarr);
		free(yarr);
		return 0;
	}
	//判断是否为相似数，如果为相似数，则ret与所有位数异或后为0
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= xarr[i];
	}
	for (i = 0; i < sz; i++)
	{
		ret ^= yarr[i];
	}
	if (ret != 0)
	{
		printf("NO\n");
		free(xarr);
		free(yarr);
		return 0;
	}
	//将xarr数组从大到小排序，使xarr中的顺序为最小相似数的顺序
	for (i = 0; i < sz; i++)
	{
		int max = i;
		for (int j = i; j < sz; j++)
		{
			if (xarr[j] > xarr[max])
				max = j;
		}
		tmp = xarr[i];
		xarr[i] = xarr[max];
		xarr[max] = tmp;
	}
	//若x含0，则将0与次小一位互换
	if (xarr[sz - 1] == 0)
	{
		int min = sz - 1;
		while (xarr[min] == 0)
		{
			min--;
		}
		xarr[sz - 1] = xarr[min];
		xarr[min] = 0;
	}
	//判断yarr是否与最小相似数的顺序一致
	for (i = 0; i < sz; i++)
	{
		if (xarr[i] != yarr[i])
		{
			printf("NO\n");
			free(xarr);
			free(yarr);
			return 0;
		}
	}
	printf("YES\n");
	free(xarr);
	free(yarr);
	return 0;
}