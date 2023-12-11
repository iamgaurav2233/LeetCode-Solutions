const int mod = 1e9 + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<vector<int>> dp(high + 1, vector<int> (2, 0));
        dp[0][0] = 1;
        for (int i = 1;i <= high; i++) {
            if (i >= zero)
            dp[i][0] = (dp[i][0] + (dp[i - zero][0] + dp[i - zero][1]) % mod) % mod;
            if (i >= one)
            dp[i][1] = (dp[i][1] + (dp[i - one][0] + dp[i - one][1]) % mod) % mod;
        }
        long long ans = 0;
        for (int i = low; i <= high; i++) {
        
            ans = (ans + dp[i][0]) % mod;
            ans = (ans + dp[i][1]) % mod;
        }
        return ans;
    }
};
