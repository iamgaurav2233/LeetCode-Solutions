class Solution {
public:
    bool validPartition(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 2 < n) {
               if (arr[i] == arr[i + 1] - 1 and arr[i + 1] == arr[i + 2] - 1)
                   dp[i] = max(dp[i], dp[i + 3]);
               if (arr[i] == arr[i + 1] and arr[i] == arr[i + 2])
                   dp[i] = max(dp[i], dp[i + 3]);
            }
            if (i + 1 < n and arr[i] == arr[i + 1]) {
                dp[i] = max(dp[i], dp[i + 2]);
            }
        }
  
        return dp[0];
    }
};
