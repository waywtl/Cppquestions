#define _CRT_SECURE_NO_WARNINGS 1

//������
//����1�������ƽ� O(mn2)
//1.��һ��width��ά�������洢�Ե�ǰ'1'Ϊ��β���������'1'�ĸ�������Ϊ���εĿ�
//2.��ÿ��'1'Ϊ���ε����½ǣ�����������չ���Կ�Ľ�Сֵ��������ֱ����һ��Ԫ�ز�Ϊ'1'��Խ��
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> width(n, vector<int>(m, 0));
        int max_area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (j == 0)
                        width[i][j] = 1;
                    else
                        width[i][j] = width[i][j - 1] + 1;

                    int min_width = width[i][j];
                    for (int index = i; (index >= 0) && (matrix[index][j] == '1'); --index)
                    {
                        int height = i - index + 1;
                        min_width = min(min_width, width[index][j]);
                        max_area = max(max_area, height * min_width);
                    }
                }
            }
        }
        return max_area;
    }
};

//������:�������½�ȡ�����������Ȼ���������84�⣬����84��Ľⷨ
// O(mn)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int weight = i;
                if (!st.empty())
                    weight = i - st.top() - 1;
                ans = max(ans, height * weight);
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int height = heights[st.top()];
            st.pop();
            int weight = n;
            if (!st.empty())
                weight = n - st.top() - 1;
            ans = max(ans, height * weight);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(m, 0);
        int max_area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    ++v[j];
                }
                else
                {
                    v[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(v));
        }
        return max_area;
    }
};

//���鼯��Ӧ��
//ʡ������
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<int> ufs(n, -1);
        auto findroot = [&ufs](int x)
        {
            while (ufs[x] >= 0)
                x = ufs[x];
            return x;
        };
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    int root1 = findroot(i);
                    int root2 = findroot(j);
                    if (root1 != root2)
                    {
                        ufs[root1] += ufs[root2];
                        ufs[root2] = root1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ufs[i] < 0)
                ++ans;
        }
        return ans;
    }
};

//��ʽ���̵Ŀ�������
class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        vector<int> ufs(26, -1);
        auto FindRoot = [&ufs](int x)
        {
            while (ufs[x] >= 0)
                x = ufs[x];
            return x;
        };

        for (string& s : equations)
        {
            if (s[1] == '=')
            {
                int r1 = FindRoot(s[0] - 'a');
                int r2 = FindRoot(s[3] - 'a');
                if (r1 != r2)
                {
                    ufs[r1] += ufs[r2];
                    ufs[r2] = r1;
                }
            }
        }
        for (string& s : equations)
        {
            if (s[1] == '!')
            {
                int r1 = FindRoot(s[0] - 'a');
                int r2 = FindRoot(s[3] - 'a');
                if (r1 == r2)
                    return false;
            }
        }
        return true;
    }
};