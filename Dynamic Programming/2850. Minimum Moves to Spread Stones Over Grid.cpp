class Solution {
public:
    int cost(pair<int, int> &A, pair<int, int> &B) {
        return abs(A.first - B.first) + abs(A.second - B.second);
    }

    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> A, B;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1)
                    for (int k = 0; k < grid[i][j] - 1; k++)
                        A.push_back({i, j});
                if (grid[i][j] == 0)
                    B.push_back({i, j});
            }
        }

        int n = A.size();
        int m = (1 << n);
        vector<vector<int>> dp(n + 1, vector<int>(m, 1e6));
        
        dp[n][m - 1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int mask = 0; mask < m; mask++) {
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) {
                        int newMask = mask | (1 << j);
                        dp[i][mask] = min(dp[i][mask], dp[i + 1][newMask] + cost(A[i], B[j]));
                    }
                }
            }
        }

        return dp[0][0];
    }
};
