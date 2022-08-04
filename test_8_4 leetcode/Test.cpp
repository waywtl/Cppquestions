#define _CRT_SECURE_NO_WARNINGS 1

//二叉树的序列化与反序列化
class Codec {
public:

    // Encodes a tree to a single string.
    void LevelOrder(TreeNode* root, vector<vector<int>>* ret)
    {
        queue<TreeNode*> q;
        q.push(root);
        int size = q.size();
        while (!q.empty())
        {
            vector<int> v;
            while (size--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur != nullptr)
                {
                    v.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else
                    v.push_back(1001);
            }
            ret->push_back(v);
            size = q.size();
        }
    }

    string serialize(TreeNode* root)
    {
        vector<vector<int>> ret;
        LevelOrder(root, &ret);
        string out_string;
        for (auto& v : ret)
        {
            for (auto& i : v)
            {
                if (i != 1001)
                {
                    out_string += to_string(i);
                    out_string += " ";
                }
                else
                {
                    out_string += "1001 ";
                }
            }
        }
        return out_string;
    }

    void Prase1(const string& data, vector<int>* v)
    {
        for (int i = 0, j = 0; i < data.size() && j < data.size();)
        {
            if (data[j] != ' ')
                ++j;
            else
            {
                string sub = data.substr(i, j - i);
                v->push_back(stoi(sub));
                i = j + 1;
                ++j;
            }
        }
    }

    void Prase2(const vector<int>& v, vector<vector<int>>* vv)
    {
        int index = 0;
        int times = 1;
        int size = v.size();
        while (index < size)
        {
            vector<int> tmp;
            int ign = 0;

            while (times-- && index < size)
            {
                tmp.push_back(v[index]);
                if (v[index] == 1001)
                    ++ign;
                ++index;
            }
            vv->push_back(tmp);
            times = tmp.size() * 2 - 2 * ign;
        }
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<vector<int>> vv;
        vector<int> v;
        Prase1(data, &v);
        Prase2(v, &vv);

        int flag = 0;
        map<pair<int, int>, TreeNode*> m;
        if (vv[0][0] != 1001)
            m[{0, 0}] = new TreeNode(vv[0][0]);
        for (int i = 0; i < vv.size() - 1; ++i)
        {
            int k = 0;
            for (int j = 0; j < vv[i].size(); ++j)
            {
                if (vv[i][j] == 1001)
                    continue;
                TreeNode* cur = m[{i, j}];
                int n = 0;
                for (; k < vv[i + 1].size() && n != 2; ++k)
                {
                    int num = vv[i + 1][k];
                    ++n;
                    if (num == 1001)
                    {
                        flag = flag ? 0 : 1;
                        continue;
                    }
                    TreeNode* node = new TreeNode(num);
                    m[{i + 1, k}] = node;
                    if (flag == 0)
                        cur->left = node;
                    else
                        cur->right = node;
                    flag = flag ? 0 : 1;
                }
            }
        }
        return m[{0, 0}];
    }
};