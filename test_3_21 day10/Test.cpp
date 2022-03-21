#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//反转单词序列
//方法一
class Solution {
public:
    void reverse(string& str, int begin, int end)
    {
        if (begin == end)
            return;
        while (begin < end)
        {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            ++begin;
            --end;
        }
    }

    string ReverseSentence(string str)
    {
        if (str.size() == 0)
            return str;
        int j = 0;
        for (int i = 0; i <= str.size(); ++i)
        {
            if (str[i] == ' ' || i == str.size())
            {
                reverse(str, j, i - 1);
                j = i + 1;
            }
        }
        reverse(str, 0, str.size() - 1);
        return str;
    }
};

//方法二
class Solution
{
    string ReverseSentence(string str)
    {
        string ret;
        if (str.size() == 0)
            return ret;
        int end = str.size() - 1;
        int start = str.size() - 1;
        while (start >= 0)
        {
            if (str[start] == ' ' || start == 0)
            {
                int len = end - start;
                if (start != 0)
                {
                    string tmp(str, start + 1, len);
                    ret += tmp;
                }
                else
                {
                    len += 1;
                    string tmp(str, start, len);
                    ret += tmp;
                }
                if (start != 0)
                    ret += ' ';
                end = start - 1;
            }
            --start;
        }
        return ret;
    }
};

//“之”字顺序打印二叉树
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int>> ret;
        if (pRoot == nullptr)
            return ret;
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        vector<int> v;
        int flag = 1;
        st.push(pRoot);
        while (!st.empty())
        {
            int size = st.size();
            while(size--)
            {
                TreeNode* tmp = st.top();
                st.pop();
                v.push_back(tmp->val);
                TreeNode* first = (flag == 1) ? tmp->left : tmp->right;
                TreeNode* second = (flag == 1) ? tmp->right : tmp->left;
                if (first != nullptr)
                    q.push(first);
                if (second != nullptr)
                    q.push(second);
            }
            ret.push_back(v);
            while (!q.empty())
            {
                st.push(q.front());
                q.pop();
            }
            flag = (flag == 1) ? 2 : 1;
            v.clear();
        }
        return ret;
    }
};

//BST第k小的节点
class Solution {
public:
    /*void Order(vector<int>& v, TreeNode* root)
    {
        if(root == nullptr)
            return;
        Order(v, root->left);
        v.push_back(root->val);
        Order(v, root->right);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> v;
        Order(v, root);
        return v[k-1];
    }*/
    int kthSmallest(TreeNode* root, int k)
    {
        TreeNode* node = root;
        stack<TreeNode*> st;
        do
        {
            while (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            if (!st.empty())
            {
                TreeNode* tmp = st.top();
                st.pop();
                k--;
                if (k == 0)
                    return tmp->val;
                node = tmp->right;
            }
        } while (node != nullptr || !st.empty());
        return NULL;
    }
};