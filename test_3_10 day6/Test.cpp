#define _CRT_SECURE_NO_WARNINGS 1

//判断一个序列是否可能为二叉搜索树的后序遍历序列
class Solution {
public:
    bool VerifySquenceOfBSTHelp(vector<int> v, int start, int end)
    {
        if (start >= end)
            return true;
        int i = start;
        while (v[i] < v[end])
        {
            ++i;
        }
        for (int j = i; j < end; ++j)
        {
            if (v[j] < v[end])
                return false;
        }
        return VerifySquenceOfBSTHelp(v, start, i - 1) && VerifySquenceOfBSTHelp(v, i, end - 1);
    }


    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        int end = sequence.size() - 1;
        return VerifySquenceOfBSTHelp(sequence, 0, end);
    }
};

//路径上所有值的和为某一值
class Solution {
public:
    void FindPathHelp(vector<vector<int>>& vv, vector<int>& v, int* sum, TreeNode* root, int expectNumber)
    {
        if (root == nullptr)
        {
            return;
        }
        *sum += root->val;
        v.push_back(root->val);
        FindPathHelp(vv, v, sum, root->left, expectNumber);
        FindPathHelp(vv, v, sum, root->right, expectNumber);
        if (*sum == expectNumber && root->left == nullptr && root->right == nullptr)
        {
            vector<int> tmp = v;
            vv.push_back(tmp);
        }
        *sum -= v[v.size() - 1];
        v.pop_back();
    }

    vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
    {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;
        vector<int> v;
        int sum = 0;
        FindPathHelp(vv, v, &sum, root, expectNumber);
        return vv;
    }
};