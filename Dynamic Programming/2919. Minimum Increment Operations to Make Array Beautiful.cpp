class Solution {
public:
    
    long long minIncrementOperations(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
        for (int i = 1;i <= n; i++) {
            for (int j = 2;j >= 0; j--) {
                long long ans = 1e15;
               if (j == 0 or j == 1)
               ans = min(ans, dp[i - 1][j + 1]);
               if (j == 0 and i - 2 >= 0)
               ans = min(ans, dp[i - 2][j + 2]);
               ans = min(ans, dp[i - 1][0] + max(0, k - arr[i - 1]));
               if (i - 2 >= 0)
               ans = min(ans, dp[i - 2][1] + max(0, k - arr[i - 1]));
               if (i - 3 >= 0)
               ans = min(ans, dp[i - 3][2] + max(0, k - arr[i - 1]));
               dp[i][j] = ans;
            }
        }
        long long ans1 = dp[n][0];
        return ans1;
    }
};
