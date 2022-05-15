#define _CRT_SECURE_NO_WARNINGS 1

//pre-post
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct subTree
{
    subTree(const string& pre, const string& post)
        :_pre(pre)
        , _post(post)
    {}
    string _pre;
    string _post;
};

vector<subTree> CalcSubTree(const string& pre, const string& post)
{
    //������ǰ���и��ڵ���±�
    int sub_root_pre_start_idx = 1;
    //��������Ŀ�ʼ�±�
    int sub_root_post_start_idx = 0;
    vector<subTree> v;
    while (sub_root_pre_start_idx < pre.size())
    {
        //�������ڵ���ַ�
        char sub_root = pre[sub_root_pre_start_idx];
        //�ں������ҵ����ڵ��ַ����±�
        int sub_root_post_end_idx = post.find(sub_root);
        //���������ĳ���
        int sub_tree_length = sub_root_post_end_idx - sub_root_post_start_idx + 1;
        //��ȡǰ��ͺ���
        string sub_tree_pre = pre.substr(sub_root_pre_start_idx, sub_tree_length);
        string sub_tree_post = post.substr(sub_root_post_start_idx, sub_tree_length);
        //���������������
        subTree st(sub_tree_pre, sub_tree_post);
        v.push_back(st);
        //��������һ������
        sub_root_pre_start_idx += sub_tree_length;
        sub_root_post_start_idx += sub_tree_length;
    }
    return v;
}

//����׳�
long long Factorial(int n)
{
    long long ret = 1;
    for (int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

//�������
long long CalcCom(int m, int n)
{
    if (n > m - n)
        n = m - n;
    long long down = Factorial(n);
    long long up = 1;
    for (int i = m; i >= m - n + 1; --i)
        up *= i;

    return up / down;
}

long long CalcPossibleTree(int m, const string& pre, const string& post)
{
    //ֻ��һ���ڵ�ʱ����ֻ��һ�ֿ���
    if (pre.size() == 1)
        return 1;
    //�ҳ���������
    vector<subTree> v = CalcSubTree(pre, post);
    //�ȼ�����ڵ������Ŀ�����
    long long ret = CalcCom(m, v.size());
    //�ݹ���������������п�����
    for (int i = 0; i < v.size(); ++i)
        ret *= CalcPossibleTree(m, v[i]._pre, v[i]._post);

    return ret;
}

int main()
{
    int m = 0;
    string s1, s2;
    while (cin >> m >> s1 >> s2)
    {
        if (m == 0)
            break;

        cout << CalcPossibleTree(m, s1, s2) << endl;
    }
    return 0;
}

//Rational Arithmetic (20)
#include<iostream>
using namespace std;

typedef long long ll;

struct Rational
{
    ll up;
    ll down;
};
ll GCD(ll a, ll b)
{
    return b == 0 ? a : GCD(b, a % b);
}
Rational Add(Rational a, Rational b)
{
    Rational c;
    c.down = a.down * b.down;
    c.up = a.up * b.down + b.up * a.down;
    return c;
}
Rational Minus(Rational a, Rational b)
{
    Rational c;
    c.down = a.down * b.down;
    c.up = a.up * b.down - b.up * a.down;
    return c;
}
Rational Multiply(Rational a, Rational b)
{
    Rational c;
    c.down = a.down * b.down;
    c.up = a.up * b.up;
    return c;
}
Rational Divide(Rational a, Rational b)
{
    Rational c;
    c.down = a.down * b.up;
    c.up = a.up * b.down;
    return c;
}
void Show(Rational a)
{
    bool flag = false;
    ll x = 0;
    ll y = 0;
    ll z = 0;

    if (y < 0)
    {
        y = -y;
        x = -x;
    }
    if (y == 0)
    {
        cout << "Inf";
        return;
    }
    else if (x == 0)
    {
        cout << "0";
        return;
    }
    else
    {
        if (x < 0) 
        {
            flag = true;
            x = -x;
        }
        if (flag)
            cout << "(-";
        ll temp = GCD(x, y);
        x /= temp; 
        y /= temp;
        z = x / y;
        x = x % y;
        if (z > 0)
            printf("%lld", z);
        if (z > 0 && x != 0)
            printf(" ");//ע��ո�����
        if (x != 0)
            printf("%lld/%lld", x, y);
        if (flag)
            printf(")");
        return;
    }
}
int main() {
    Rational a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    Show(a); printf(" + "); Show(b); printf(" = "); Show(Add(a, b)); printf("\n");
    Show(a); printf(" - "); Show(b); printf(" = "); Show(Minus(a, b)); printf("\n");
    Show(a); printf(" * "); Show(b); printf(" = "); Show(Multiply(a, b)); printf("\n");
    Show(a); printf(" / "); Show(b); printf(" = "); Show(Divide(a, b)); printf("\n");
    return 0;
}