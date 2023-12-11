class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (28, -1e6));
        dp[0][s[0] - 'a'] = 0;
        for (int i = 1;i < n; i++) {
            dp[i][s[i] - 'a'] = 0;
            for (int j = 0;j <= 25; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (abs((s[i] - 'a') - (int)j) <= k) {
                    dp[i][s[i] - 'a'] = max(dp[i][s[i] - 'a'], dp[i - 1][j] + 1);       
                }
                
            }
        }
        
       return *max_element(dp[n - 1].begin(), dp[n - 1].end()) + 1;
    }
};
