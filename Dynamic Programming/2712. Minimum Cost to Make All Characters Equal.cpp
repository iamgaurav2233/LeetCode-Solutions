class Solution {
public:
    long long minimumCost(string s) {
        long long n = s.size();
        vector<vector<long long>> dp(n + 2, vector<long long>(2, 0));
        vector<vector<long long>> dp2(n + 2, vector<long long>(2, 0));
        for (long long i = 1;i <= n; i++) {
            if (s[i - 1] == '0') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + i - 1);
            dp[i][1] = min(dp[i - 1][1] + 2 * i - 1, dp[i - 1][0] + i);
            }
            else {
            dp[i][0] = min(dp[i - 1][0] + 2 * i - 1, dp[i - 1][1] + i);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + i - 1);
            }
        }
        for (long long i = n;i >= 1; i--) {
            if (s[i - 1] == '0') {
                dp2[i][0] = min({dp2[i + 1][0], dp2[i + 1][1] + n - i});
                dp2[i][1] = min({dp2[i + 1][1] + 2 * (n - i) + 1, dp2[i + 1][0] + (n - i) + 1});
            }
            else {
                dp2[i][0] = min({dp2[i + 1][0] + 2 * (n - i) + 1, dp2[i + 1][1] + (n - i) + 1});
                dp2[i][1] = min({dp2[i + 1][1], dp2[i + 1][0] + n - i});
            }
        }
     
        long long ans1 = LLONG_MAX, ans2 = LLONG_MAX;
        for (long long i = 0;i <= n; i++) {
             ans1 = min(ans1, dp[i][0] + dp2[i + 1][0]);
             ans2 = min(ans2, dp[i][1] + dp2[i + 1][1]);
        }
        return min(ans1, ans2);
    }
};
