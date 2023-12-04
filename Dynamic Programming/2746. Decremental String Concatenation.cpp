class Solution {
public:
    int minimizeConcatenatedLength(vector<string> &w) {
        int n = w.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (26, vector<int> (26, 1e9)));
        dp[0][w[0][0] - 'a'][w[0].back() - 'a'] = w[0].size();
        for (int i = 1;i < n; i++) {
            for (int j = 0;j < 26; j++) {
                for (int k = 0;k < 26; k++) {
                 dp[i][j][w[i].back() - 'a'] = min(dp[i][j][w[i].back() - 'a'] ,dp[i - 1][j][k] + (int)w[i].size() - (int)(k == (w[i][0] -'a')));
                 dp[i][w[i][0] - 'a'][k] = min(dp[i][w[i][0] - 'a'][k], dp[i - 1][j][k] + (int)w[i].size() - (int)((w[i].back() - 'a') == j));
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0;i < 26; i++) {
            for (int j = 0;j < 26; j++) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
    }
};
