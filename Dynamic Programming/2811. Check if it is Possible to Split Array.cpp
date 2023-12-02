class Solution {
public:
    int dp[102][102];
    int m;
    bool recur(int i, int j, vector<int> &pre) {
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool ans = 0;
        for (int k = i; k < j; k++) {
            if ((k - i == 0 or pre[k] - pre[i - 1] >= m) and (j - k - 1 == 0 or pre[j] - pre[k] >= m))
                ans = (ans | (recur(i, k, pre) & recur(k + 1, j, pre)));
        }
        return dp[i][j] = ans;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        this->m = m;
        vector<int> pre(n + 1, 0);
        for (int i = 0;i < n; i++)
            pre[i + 1] = nums[i];
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i] + pre[i - 1];
        memset(dp, -1, sizeof(dp));
        bool ans = recur(1, n, pre);
        return ans;
    }
};


class Solution {
public: 
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0;i < n; i++)
            pre[i + 1] = nums[i];
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i] + pre[i - 1];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 0;i <= n; i++) dp[i][i] = 1;
        for (int sze = 1;sze <= n; sze++) {
            for (int i = 1;i <= n - sze + 1; i++) {
                int j = sze + i - 1;
                for (int k = i; k < j; k++) {
                   if ((k - i == 0 or pre[k] - pre[i - 1] >= m) and (j - k - 1 == 0 or pre[j] - pre[k] >= m))
                      dp[i][j] = (dp[i][j] | (dp[i][k] & dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
