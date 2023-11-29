class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (tar + 1, -1e6));
        for (int i = 0;i <= n; i++) dp[i][0] = 0;
        for (int i = 1;i <= n; i++) {
            for (int j = 1;j <= tar; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - arr[i - 1] >= 0)
                   dp[i][j] = max(dp[i][j], dp[i - 1][j  - arr[i - 1]] + 1);
            }
        }
        return (dp[n][tar] >= 0 ? dp[n][tar] : -1);
    }
};
