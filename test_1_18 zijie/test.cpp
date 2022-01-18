#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//ϸ������
//��Ŀ��
//С������ĳ������ϸ�����ѵ�������Ȥ�Ĺ��ɣ�
//   1.���ֻ��һ��ϸ������ϸ��������ÿһ�����з��ѣ���1��ϸ�����2��ϸ��������
//     �·��ѵ�ϸ��������ÿһ��Ҳ����з��ѡ�
//   2.ÿK��ϸ���ۺϳ�һ�飬ʣ�²���K��ϸ���ۺϳ�һ�顣����ϸ��Ҳ���¹¶����ӵ�2��
//     ��ʼ���������飨�����ڵ�ϸ������Ϊ1����ϸ�����������
//���Ǽ���ÿ�ε����Ķ�������ϸ����С����֪����N����ж���ϸ����������������ܱȽϴ�
//����Ҫ��2022*K����ȡģ

//���룺һ�У�N K
//�����һ�У���N����ϸ��

int CellNum(int n, int k)
{
	long long curOldCell, curNewCell, prevOldCell, prevNewCell;
	curOldCell = 1;
	curNewCell = 0;
	long long num = curOldCell + curNewCell;
	int i = 1;
	while (i < n)
	{
		++i;
		prevOldCell = curOldCell;
		prevNewCell = curNewCell;

		//��һ����ϸ������Ϊǰһ��ϸ����,��ϸ������Ϊǰһ����ϸ����
		curOldCell = prevOldCell + prevNewCell;
		curNewCell = prevOldCell;
		num = curOldCell + curNewCell;

		//���¶���ϸ����ȥ
		if (num % k == 1)
		{
			--num;
			--curNewCell;
		}
	}
	return num;
}

int main()
{
	int N = 0;
	int K = 0;
	cin >> N;
	cin >> K;
	long long num = CellNum(N, K);
	cout << num << endl;
	return 0;
}

//��С������
//��Ŀ��
//��������x�����������λ���õ�������YΪ��������������ǰ��0�������磬
//"1123"��"1213"��"3211"��"3121"����������"1001"��"0011"������������
//��Ϊ"0011"������ǰ��0;�ָ�����������X,Y�����ж�Y�Ƿ�ΪX����С��������

//���룺һ�� X��������ǰ��0��
//�����һ�� Y������ǰ��0��

const char* MinSimilar(int x, int y)
{
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
		return "NO";
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
		free(xarr);
		free(yarr);
		return "NO";
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
		free(xarr);
		free(yarr);
		return "NO";
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
			free(xarr);
			free(yarr);
			return "NO";
		}
	}
	free(xarr);
	free(yarr);
	return "YES";
}

int main()
{
	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;
	const char* ret = MinSimilar(x, y);
	cout << ret << endl;
	return 0;
}

//�����
//��Ŀ:
//��N���ؿ���ÿ���ؿ���һֻ���ޣ���ܹ��޿��Ի�ȡ����ֵ����Ȼ��Ҳ���ܱ�����
//��ܶ�ʧȥ����ֵ��ͨ��������뱻��ܾ�����ͨ������i���ؿ�����ܽ����i+1
//���ؿ���Сǿ��������Ϸ�е�һ��BUG���ܹ�����ѡ����ĸ��ؿ���ʼս����Сǿ��
//�ٻ���ҪK�㾭���������������֪��������Ҫͨ�������ؿ��ܹ�������

//���룺��һ�У�N K
//     �ڶ��У�N����������ʾÿ���ؿ��ľ���ֵ
//�����һ�У�����ͨ�����ٹ����������޷������������-1

int HitMonster(int n, int k,int* a)
{
	int i = 0;
	int j = 0;
	int minLevelNum = n + 1;
	//�Ӻ���ǰ������������ĳһ����ʱ���Ӹ�����ʼ�������
	//ÿ��һ�أ��Ͱ��ܻ�õ��ܾ���ֵ���������辭��ֵ���
	for (i = n-1; i >= 0 ; --i)
	{
		int levelNum = 0;
		int expSum = 0;
		for (j = i; j < n; ++j)
		{
			expSum += a[j];
			levelNum++;
			if (expSum >= k && levelNum < minLevelNum)
			{
				minLevelNum = levelNum;
			}
		}
	}
	if (minLevelNum != (n + 1))
		return minLevelNum;
	else
		return -1;
}

int main()
{
	int N = 0;
	int K = 0;
	cin >> N;
	cin >> K;
	int* a = (int*)malloc(sizeof(int) * N);
	if (a == nullptr)
	{
		cout << "malloc fail" << endl;
		exit(-1);
	}
	int i = 0;
	while (i < N)
	{
		cin >> a[i];
		++i;
	}

	cout << HitMonster(N, K, a) << endl;
	return 0;
}