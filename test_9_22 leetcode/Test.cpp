#define _CRT_SECURE_NO_WARNINGS 1

//�ܷ������γ�����
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        bool ret = true;;
        for (auto& v : pieces)
        {
            int num = v[0];
            int i = 0;
            for (; i < arr.size(); ++i)
            {
                if (arr[i] == num)
                    break;
            }

            if (i == arr.size())
            {
                ret = false;
                break;
            }

            for (int j = 0; j < v.size(); ++j)
            {
                if (v[j] != arr[i++])
                {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }
};