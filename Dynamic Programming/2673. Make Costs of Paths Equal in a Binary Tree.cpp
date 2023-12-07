class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        auto dfs = [&](int v, auto&&dfs)->void{
                    if (2 * v + 1 < cost.size()) 
                    dfs(2 * v + 1, dfs);
                    else {
                        return;
                    }
                    dfs(2 * v + 2, dfs);
                ans += abs(cost[2 * v + 1] - cost[2 * v + 2]);
                cost[v] += max(cost[2 * v + 1], cost[2 * v + 2]);
        };
        dfs(0, dfs);
        return ans;
    }
};
