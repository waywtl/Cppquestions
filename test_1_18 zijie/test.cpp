#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//细胞分裂
//题目：
//小万发现了某种神奇细胞分裂的两个有趣的规律：
//   1.起初只有一个细胞，该细胞两秒后的每一秒会进行分裂（即1个细胞变成2个细胞），其
//     新分裂的细胞两秒后的每一秒也会进行分裂。
//   2.每K个细胞聚合成一组，剩下不满K个细胞聚合成一组。由于细胞也害怕孤独，从第2秒
//     开始，单个成组（即组内的细胞个数为1）的细胞将会凋亡。
//我们假设每次凋亡的都是新生细胞，小万想知道第N秒后有多少细胞？由于这个数可能比较大，
//你需要对2022*K进行取模

//输入：一行，N K
//输出：一行，第N秒后的细胞

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

		//这一秒老细胞个数为前一秒细胞数,新细胞个数为前一秒老细胞数
		curOldCell = prevOldCell + prevNewCell;
		curNewCell = prevOldCell;
		num = curOldCell + curNewCell;

		//将孤独的细胞除去
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

//最小相似数
//题目：
//定义整数x经过随机交换位数得到的整数Y为相似数（不包含前导0），例如，
//"1123"和"1213"、"3211"、"3121"是相似数，"1001"和"0011"不是相似数，
//因为"0011"包含了前导0;现给定两个整数X,Y，请判断Y是否为X的最小相似数。

//输入：一行 X，不包含前导0；
//输出：一行 Y，包含前导0；

const char* MinSimilar(int x, int y)
{
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
		return "NO";
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
		free(xarr);
		free(yarr);
		return "NO";
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
		free(xarr);
		free(yarr);
		return "NO";
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

//打怪兽
//题目:
//有N个关卡，每个关卡有一只怪兽，打败怪兽可以获取经验值，当然，也可能被怪兽
//打败而失去经验值。通过（打败与被打败均算作通过）第i个关卡后才能进入第i+1
//个关卡。小强发现了游戏中的一个BUG，能够自行选择从哪个关卡开始战斗。小强至
//少还需要K点经验才能升级，他想知道最少需要通过几个关卡能够升级？

//输入：第一行，N K
//     第二行，N个整数，表示每个关卡的经验值
//输出：一行，最少通过多少关升级，若无法升级，请输出-1

int HitMonster(int n, int k,int* a)
{
	int i = 0;
	int j = 0;
	int minLevelNum = n + 1;
	//从后往前遍历，遍历到某一个数时，从该数开始往后遍历
	//每过一关，就把能获得的总经验值与升级所需经验值相比
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