#define _CRT_SECURE_NO_WARNINGS 1

//ÊÖÌ×
class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right)
    {
        int leftSum = 0;
        int rightSum = 0;
        int leftMin = INT_MAX;
        int rightMin = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (left[i] == 0 || right[i] == 0)
                sum += left[i] + right[i];
            else
            {
                leftSum += left[i];
                leftMin = min(leftMin, left[i]);
                rightSum += right[i];
                rightMin = min(rightMin, right[i]);
            }
        }
        return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
    }
};