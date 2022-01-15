#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��С������
int main()
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	//����x,y��λ��
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
	//��x,y��ÿһλ������Ӧ������
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
	//���y��ǰ��Ϊ0
	if (yarr[sz - 1] == 0)
	{
		printf("NO\n");
		free(xarr);
		free(yarr);
		return 0;
	}
	//�ж��Ƿ�Ϊ�����������Ϊ����������ret������λ������Ϊ0
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
	//��xarr����Ӵ�С����ʹxarr�е�˳��Ϊ��С��������˳��
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
	//��x��0����0���Сһλ����
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
	//�ж�yarr�Ƿ�����С��������˳��һ��
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