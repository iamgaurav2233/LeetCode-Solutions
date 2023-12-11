const int mod = 1e9 + 7;
class Solution {
public:
    int dp[3001][1001];
    int recur(int i, int j, int k) {
        if (j == 0) {
            if  (i == k)
                return 1;
            else return 0;
        }
        if (dp[i + 1000][j] != -1)
            return dp[i + 1000][j];
        long long ans = 0;
        ans = (ans + recur(i + 1, j - 1, k)) % mod;
        ans = (ans + recur(i - 1, j - 1, k)) % mod;
        return dp[i + 1000][j] = ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = recur(startPos, k, endPos);
        return ans;
    }
};
