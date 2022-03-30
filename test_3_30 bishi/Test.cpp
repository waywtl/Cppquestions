#define _CRT_SECURE_NO_WARNINGS 1

//不使用运算符的加法
class Solution
{
public:
	int Add(int a, int b)
	{
		int num = a ^ b;
		int carry = (a & b) << 1;
		while (carry != 0)
		{
			a = num;
			b = carry;
			num = a ^ b;
			carry = (a & b) << 1;
		}
		return num;
	}
};
