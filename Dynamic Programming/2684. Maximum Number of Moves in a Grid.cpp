class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto ok = [&](int x, int y)->bool{
          return x >= 0 and y >= 0 and x < n and y < m;  
        };
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MIN));
        for (int i = 0;i < n; i++) dp[i][0] = 0;
        for (int j = 0;j < m; j++) {
            for (int i = 0;i < n; i++) {
                if (ok(i + 1, j + 1) and grid[i + 1][j + 1] > grid[i][j])
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                if (ok(i - 1, j + 1) and grid[i - 1][j + 1] > grid[i][j])
                dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j] + 1);
                if (ok(i, j + 1) and grid[i][j + 1] > grid[i][j])
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
            }
        }
        int maxi = INT_MIN;
        for (int i = 0;i < n; i++) {
            for (int j = 0;j < m; j++) {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};
