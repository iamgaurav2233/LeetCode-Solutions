class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& e, vector<int>& val){
        long long n = val.size();
        vector<vector<long long>> adj(n);
        for (long long i = 0;i < e.size(); i++) {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        vector<long long> dp(n);
        auto dfs = [&](long long v, long long p, auto&& dfs)->void{
            for (auto &u: adj[v]) {
                if (p != u) {
                    dfs(u, v, dfs);
                    dp[v] += dp[u];
                }
            }
            if (v != 0 and adj[v].size() == 1) 
                dp[v] = val[v];
            else 
            dp[v] = max(dp[v], (long long)val[v]);
        };  
        dfs(0, n, dfs);
        return dp[0];
    }
};
