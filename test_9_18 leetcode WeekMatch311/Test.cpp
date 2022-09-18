#define _CRT_SECURE_NO_WARNINGS 1

//最小偶数倍
class Solution {
public:
    int smallestEvenMultiple(int n)
    {
        if (n % 2 == 0)
            return n;
        else
            return 2 * n;
    }
};

//最长的字母序连续子字符串的长度
class Solution {
public:
    int longestContinuousSubstring(string s)
    {
        int ans = 1;
        int n = s.size();
        int cur = 1;
        for (int i = 0, j = 1; j < n; ++j)
        {
            if (s[j] - s[j - 1] == 1)
            {
                ++cur;
                ans = max(ans, cur);
            }
            else
            {
                i = j;
                cur = 1;
            }

        }
        //ans = max(ans, cur);
        return ans;
    }
};

//反转二叉树的奇数层
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int size = q.size();
        vector<int> v;


        while (!q.empty())
        {
            int i = v.size() - 1;
            while (size--)
            {
                TreeNode* node = q.front();
                q.pop();
                if (level % 2 != 0)
                {
                    node->val = v[i--];
                }

                if (node->left)
                {
                    q.push(node->left);
                    if (level % 2 == 0)
                        v.push_back(node->left->val);
                }
                if (node->right)
                {
                    q.push(node->right);
                    if (level % 2 == 0)
                        v.push_back(node->right->val);
                }
            }
            ++level;
            if (level % 2 == 0)
                v.clear();
            size = q.size();
        }
        return root;
    }
};

//字符串的前缀分数和
class Solution {
    struct Node
    {
        Node* next[26] = { nullptr };
        int score = 0;
    };

    vector<int> ans;

public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        int n = words.size();
        Node* root = new Node();
        for (auto& s : words)
        {
            Node* cur = root;
            for (auto& c : s)
            {
                int i = c - 'a';
                if (cur->next[i] == nullptr)
                {
                    cur->next[i] = new Node();
                }
                cur = cur->next[i];
                ++cur->score;
            }
        }

        ans.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            Node* cur = root;
            int sum = 0;
            for (auto& c : words[i])
            {
                int index = c - 'a';
                if (cur->next[index] == nullptr)
                    break;
                cur = cur->next[index];
                sum += cur->score;
            }
            ans[i] = sum;
        }

        return ans;
    }
};