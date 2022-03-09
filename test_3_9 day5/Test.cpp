#define _CRT_SECURE_NO_WARNINGS 1

//包含min函数的栈
class Solution {
public:
    void push(int value)
    {
        data_stack.push(value);
        if (min_stack.size() == 0 || value < min_stack.top())
        {
            min_stack.push(value);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }
    void pop()
    {
        if (data_stack.size() == 0 || min_stack.size() == 0)
            return;
        data_stack.pop();
        min_stack.pop();
    }
    int top()
    {
        return data_stack.top();
    }
    int min()
    {
        return min_stack.top();
    }
private:
    stack<int> data_stack;
    stack<int> min_stack;
};

//出栈序列判定
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
            return false;
        stack<int> st;
        int i = 0;
        int j = 0;
        for (i = 0; i < pushV.size(); ++i)
        {
            st.push(pushV[i]);
            while (!st.empty() && st.top() == popV[j])
            {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};

//层序遍历二叉树
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            v.push_back(tmp->val);
            q.pop();

            if (tmp->left != nullptr)
                q.push(tmp->left);
            if (tmp->right != nullptr)
                q.push(tmp->right);
        }
        return v;
    }
};