#define _CRT_SECURE_NO_WARNINGS 1

//最长数对链
//方法1：暴力 O(n2)
class Solution {
public:
	 int findLongestChain(vector<vector<int>>& pairs)
	 {
	     int n = pairs.size();
	     sort(pairs.begin(), pairs.end());
	     vector<int> dp(n, 0);
	     dp[0] = 1;
	     for(int i = 1; i < n; ++i)
	     {
	         int pre_max = 0;
	         for(int j = i-1; j >= 0; --j)
	         {
	             if(pairs[i][0] > pairs[j][1])
	                 pre_max = max(pre_max, dp[j]);
	         }
	         dp[i] = pre_max + 1;
	     }
	     return dp[n-1];
	 }
};

//方法2：类似递增子序列，用一个数组记录最优解
class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs)
	{
		sort(pairs.begin(), pairs.end());
		vector<int> arr;
		for (auto& p : pairs)
		{
			int x = p[0];
			int y = p[1];
			if (arr.size() == 0 || arr.back() < x)
				arr.push_back(y);
			else
			{
				int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
				arr[index] = min(arr[index], y);
			}
		}
		return arr.size();
	}
};

//特定深度节点链表
class Solution {
public:
	vector<ListNode*> listOfDepth(TreeNode* tree)
	{
		vector<ListNode*> ret;
		queue<TreeNode*> q;
		q.push(tree);
		while (!q.empty())
		{
			int sz = q.size();
			ListNode* head = new ListNode(0);
			ListNode* tail = head;
			while (sz--)
			{
				TreeNode* node = q.front();
				q.pop();
				ListNode* new_node = new ListNode(node->val);
				tail->next = new_node;
				tail = new_node;

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			ret.push_back(head->next);
		}
		return ret;
	}
};

//找出第N个二进制字符串中的第K位
//方法1：暴力
class Solution {
public:
	char findKthBit(int n, int k)
	{
		vector<string> dp(n + 1, "");
		dp[1] = "0";
		for (int i = 2; i < n + 1; ++i)
		{
			string prev = dp[i - 1];
			string un_prev = prev;
			for (auto& ch : un_prev)
				ch = (ch == '0') ? '1' : '0';

			reverse(un_prev.begin(), un_prev.end());
			dp[i] = prev + "1" + un_prev;
		}
		return *(dp[n].begin() + k - 1);
	}
};

//方法2：递归
class Solution {
public:
	char findKthBit(int n, int k)
	{
		if (k == 1)
			return '0';
		int mid = 1 << (n - 1);
		if (k == mid)
			return '1';
		else if (k < mid)
			return findKthBit(n - 1, k);
		else
		{
			k = mid * 2 - k;
			return findKthBit(n - 1, k) == '0' ? '1' : '0';
		}
	}
};