class Solution {
public:
      int cost(pair<int, int> &A, pair<int, int> &B) {
        return abs(A.first - B.first) + abs(A.second - B.second);
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> A, B;
        for (int i = 0;i < 3; i++) {
            for (int j = 0;j < 3; j++) {
                if (grid[i][j] > 1)
                    for (int k = 0;k < grid[i][j] - 1; k++)
                        A.push_back({i, j});
                if (grid[i][j] == 0)
                    B.push_back({i, j});
            }
        }
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int> ((1 << n), 1e6));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0;j < (1 << n); j++) {
                if(__builtin_popcountll(j) != i - 1) continue;
                int ans = 1e6;
                for (int k = 0;k < n; k++) {
                    if (!(j & (1 << k)))
                        dp[i][j | (1 << k)] = min(dp[i][j | (1 << k)], dp[i - 1][j] + cost(A[i - 1], B[k]));
                }
            }
        }
        return dp[n][(1 << n) - 1];
    }
};
