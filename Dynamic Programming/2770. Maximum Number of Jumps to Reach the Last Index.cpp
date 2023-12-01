class Solution {
public:

    int maximumJumps(vector<int>& arr, int t) {
       int n = arr.size(); 
        vector<int> dp(n + 1, -1e6);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1;j >= 1; j--) {
                if (arr[i - 1] - arr[j - 1] >= -t and arr[i - 1] - arr[j - 1] <= t)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[n] < 0) return -1;
        else return dp[n];
    }
};
