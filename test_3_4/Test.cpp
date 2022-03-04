#define _CRT_SECURE_NO_WARNINGS 1

//1609.ÆæÅ¼Ê÷
class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        TreeNode* queue[100001];
        int front = 0;
        int rear = 0;
        int pre = 0;

        int flag = 0;

        queue[rear++] = root;
        while (front != rear)
        {
            int cnt = rear - front;
            if (flag == 0)
                pre = INT_MIN;
            else
                pre = INT_MAX;

            for (int i = 0; i < cnt; ++i)
            {
                root = queue[front++];
                if ((flag == 0) && (root->val % 2 != 1 || pre >= root->val))
                    return false;
                if ((flag == 1) && (root->val % 2 != 0 || pre <= root->val))
                    return false;

                pre = root->val;
                if (root->left != nullptr)
                    queue[rear++] = root->left;
                if (root->right != nullptr)
                    queue[rear++] = root->right;
            }
            flag = (flag + 1) % 2;
        }
        return true;
    }
};