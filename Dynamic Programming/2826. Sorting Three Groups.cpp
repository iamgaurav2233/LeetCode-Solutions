class Solution {
public:
    int minimumOperations(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (4, 0));
        for (int i = 1;i <= n; i++) {
            dp[i][1] = dp[i - 1][1] + (int)(arr[i - 1] != 1);
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (int)(arr[i - 1] != 2);
            dp[i][3] = min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + (int)(arr[i - 1] != 3);
        }
        return *min_element(dp[n].begin() + 1, dp[n].end());
    }
};
