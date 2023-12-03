class Solution {
public:
const int mod = 1e9 + 7;
int powmod(int a, int b) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int numberOfWays(int n, int x) {
    vector<int> arr;
    for (int i = 1; powmod(i, x) <= n; i++) {
        arr.push_back(powmod(i, x));
    }
    int m = arr.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    for (int i = 1;i <= m; i++) {
        for (int j = 1;j <= n; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j >= arr[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % mod;
            }
        }
    }

    return dp[m][n];
}
};
