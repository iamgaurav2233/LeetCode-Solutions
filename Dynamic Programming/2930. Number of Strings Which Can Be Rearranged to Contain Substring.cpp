const long long mod = 1e9 + 7;
class Solution {
public:
    
    long long stringCount(long long n) {
        vector<vector<long long>> dp(n + 1,vector<long long> (16, 0));
        dp[0][0] = 1;
        for (long long i = 1;i <= n; i++) {      
            for (long long j = 0;j <= 15; j++) {
               long long ans = 0;
                ans = (ans + dp[i - 1][j & 14]) % mod;
                if ((j & 4) == 0)
                    ans = (ans + dp[i - 1][j & 13]) % mod;
                else
                    ans = (ans + dp[i - 1][j & 11]) % mod;
                ans = (ans + dp[i - 1][j & 7]) % mod;
                ans = (ans + (23 * dp[i - 1][j]) % mod) % mod;
                dp[i][j] = ans;
            }
        }
        return dp[n][15];
    }
};
