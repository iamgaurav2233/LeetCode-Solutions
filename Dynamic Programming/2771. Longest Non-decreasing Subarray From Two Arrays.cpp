class Solution {
public:
    
    int maxNonDecreasingLength(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        for (int i = 1;i < n; i++) {
            if (arr1[i] >= arr1[i - 1])
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            if (arr1[i] >= arr2[i - 1])
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            if (arr2[i] >= arr1[i - 1])
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            if (arr2[i] >= arr2[i - 1])
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
        }
        int ans = 0;
        for (int i = 0;i < n; i++)
            ans = max({ans, dp[i][0], dp[i][1]});
        return ans + 1;
    }
};
