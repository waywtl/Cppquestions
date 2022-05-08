#define _CRT_SECURE_NO_WARNINGS 1

//前K个高频单词
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> countMap;
        for (auto& str : words)
        {
            ++countMap[str];
        }

        multimap<int, string, greater<int>> sortMap;
        for (auto& kv : countMap)
        {
            sortMap.insert(make_pair(kv.second, kv.first));
        }

        vector<string> ret;
        auto it = sortMap.begin();
        while (k--)
        {
            ret.push_back(it->second);
            ++it;
        }
        return ret;
    }
};