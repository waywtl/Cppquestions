#define _CRT_SECURE_NO_WARNINGS 1

//���ݿ���
class Solution {
public:
    int bulbSwitch(int n)
    {
        int ans = 0;
        int i = 1;
        while (i * i <= n)
        {
            ++ans;
            ++i;
        }

        return ans;

        //�ж���һ����֮ǰ�����������������ȫƽ�����ĸ���
        //return sqrt(n+0.5);
    }
};

//���ݿ��آ�
class Solution {
public:
    int flipLights(int n, int presses)
    {
        if (presses == 0)
            return 1;

        if (n == 1)
            return 2;
        else if (n == 2)
            return presses == 1 ? 3 : 4;
        else
            return presses == 1 ? 4 : (presses == 2 ? 7 : 8);
    }
};