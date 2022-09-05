#define _CRT_SECURE_NO_WARNINGS 1

//寻找重复的子树
class Solution {
public:
    unordered_map<string, int> m;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root)
    {
        if (root == nullptr)
            return "";

        string s = to_string(root->val) + " " + dfs(root->left) + " " + dfs(root->right);
        m[s]++;
        if (m[s] == 2)
            ans.push_back(root);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};

//整理字符串
class Solution {
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (auto& ch : s)
        {
            if (st.empty() || (ch - st.top() != 32 && ch - st.top() != -32))
                st.push(ch);
            else
                st.pop();
        }

        int len = st.size();
        string ans(len, ' ');
        int i = len - 1;
        while (!st.empty() && i >= 0)
        {
            char ch = st.top();
            st.pop();
            ans[i] = ch;
            --i;
        }
        return ans;
    }
};

//猜数字游戏
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int len = secret.size();
        int A_cnt = 0;
        unordered_map<int, int> ms;
        unordered_map<int, int> mg;
        for (int i = 0; i < len; ++i)
        {
            if (secret[i] == guess[i])
                ++A_cnt;
            else
            {
                ms[secret[i] - '0']++;
                mg[guess[i] - '0']++;
            }
        }

        int B_cnt = 0;
        for (auto& p : mg)
        {
            if (ms.find(p.first) != ms.end())
                B_cnt += min(p.second, ms[p.first]);
        }
        string ans = to_string(A_cnt) + "A" + to_string(B_cnt) + "B";
        return ans;
    }
};