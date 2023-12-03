class Solution {
public:
/*
[2, 99]
50
*/
long long maxScore(vector<int>& arr, int x) {
      int n = arr.size();
      vector<vector<long long>> dp(n + 1, vector<long long> (2, -1e14));
      dp[0][0] = dp[0][1] = 0;
      dp[1][0] = arr[0] - (arr[0] % 2 ? x : 0);
      dp[1][1] = arr[0] - (arr[0] % 2 ? 0 : x);
      for (int i = 2;i <= n; i++) {
          dp[i][0] = max(dp[i - 1][1] - x, dp[i - 1][0]) + (arr[i - 1] % 2 ? 0 : arr[i - 1]);
          dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - x) + (arr[i - 1] % 2 ? arr[i - 1] : 0);   
      }
    return max(dp[n][1], dp[n][0]);
}
};
