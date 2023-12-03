class Solution {
public:
bool isPower(int x, int y)
{
    float res1 = log(y) / log(x);
    return res1==floor(res1);
}
int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 1e6));
       for (int i = 0;i < n; i++) {
            if (s[i] == '0')
                continue;
            for (int j = i;j < n; j++) {
                int cnt = 0;
                for (int k = j, f = 0; k >= i; k--, f++) {
                    if (s[k] == '1')
                        cnt += (1 << f);
                }
                if (isPower(5, cnt))
                    dp[i + 1][j + 1] = 0;
            }
        }
        for (int sz = 1; sz <= n; sz++) {
            for (int i = 1; i <= n - sz + 1; i++) {
                int j = i + sz - 1;
                for (int k = i; k < j; k++) {
                         dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
        if (dp[1][n] >= 1e6) return -1;
        else return dp[1][n] + 1;
    }
};
