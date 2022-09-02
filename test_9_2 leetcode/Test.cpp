#define _CRT_SECURE_NO_WARNINGS 1

//查询带键的排列
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        int n = queries.size();
        vector<int> ret;
        unordered_map<int, int> m1;
        for (int i = 0; i < m; ++i)
            m1[i + 1] = i;

        for (auto& x : queries)
        {
            int index = m1[x];
            ret.push_back(index);
            for (auto& p : m1)
            {
                if (p.second < index)
                    ++p.second;
            }
            m1[x] = 0;
        }
        return ret;
    }
};

//句子相似性Ⅲ
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);

        int len1 = sentence1.size();
        int len2 = sentence2.size();
        vector<string> v1;
        vector<string> v2;

        string s;
        for (int i = 0; i < len1; ++i)
        {
            if (sentence1[i] != ' ')
                s += sentence1[i];
            else
            {
                v1.push_back(s);
                s = "";
            }
        }
        v1.push_back(s);
        s = "";

        for (int i = 0; i < len2; ++i)
        {
            if (sentence2[i] != ' ')
                s += sentence2[i];
            else
            {
                v2.push_back(s);
                s = "";
            }
        }
        v2.push_back(s);

        int m = v1.size();
        int n = v2.size();
        int i = 0;
        while (i < n && v1[i] == v2[i])
        {
            ++i;
        }
        if (i == n)
            return true;

        int j = 0;
        while (j < n && v1[m - 1 - j] == v2[n - 1 - j])
        {
            ++j;
        }
        if (j == n)
            return true;

        if (i + j == n)
            return true;
        return false;
    }
};