#define _CRT_SECURE_NO_WARNINGS 1

//���ݶ����������ַ���
class Solution {
public:
    void _tree2str(TreeNode* root, string& s)
    {
        if (root == nullptr)
            return;

        s += to_string(root->val);
        if (root->left || root->right)
        {
            s += '(';
            _tree2str(root->left, s);
            s += ')';
        }

        if (root->right)
        {
            s += '(';
            _tree2str(root->right, s);
            s += ')';
        }
    }

    string tree2str(TreeNode* root)
    {
        string ret;
        _tree2str(root, ret);
        return ret;
    }
};

//�������Ĳ������
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        queue<TreeNode*> q;

        if (root == nullptr)
            return ret;

        q.push(root);
        int levelSize = 1;
        while (!q.empty())
        {
            vector<int> v;
            while (levelSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            levelSize = q.size();
            ret.push_back(v);
        }
        return ret;
    }
};

//�����������������
class Solution {
public:
    bool FindPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;
        path.push_back(root);
        if (root == node)
            return true;
        if (FindPath(root->left, node, path))
            return true;
        if (FindPath(root->right, node, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
            return nullptr;
        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;

        FindPath(root, p, pPath);
        FindPath(root, q, qPath);

        int pSize = pPath.size();
        int qSize = qPath.size();
        int minSize = pSize > qSize ? qSize : pSize;
        TreeNode* ret = nullptr;
        for (int i = 0; i < minSize; ++i)
        {
            if (i + 1 >= pSize || i + 1 >= qSize || pPath[i + 1] != qPath[i + 1])
            {
                ret = pPath[i];
                break;
            }
        }
        return ret;
    }
};