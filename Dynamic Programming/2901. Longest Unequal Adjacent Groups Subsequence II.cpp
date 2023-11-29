class Solution {
public:

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
        vector<vector<int>> hd(n, vector<int>(n, 0));
        for (int i = 0;i < n; i++) {
            for (int j = i + 1;j < n; j++) {
                if (g[i] == g[j] or w[i].size() != w[j].size())continue;
                int cnt = 0;
                for (int k = 0;k < w[i].size(); k++)
                    if (w[i][k] != w[j][k]) {
                        cnt++;
                        if (cnt == 2) break;
                    }
                if (cnt == 1 and g[i] != g[j])
                 hd[j][i] = cnt, hd[i][j] = cnt;
            }
        }
         vector<pair<int, int>> dp(n);
             dp[0] = {1, -1};
         vector<string> ans;
         int ansMax = 1, idx = 0;
        for (int i = 1; i < n; i++) {
             int maxi = 1, ind = -1;
             for (int j = i - 1;j >= 0; j--) {
                 if (hd[i][j] and maxi < dp[j].first + 1) {
                     maxi = dp[j].first + 1;
                     ind = j;
                 }
             }
             dp[i] = {maxi, ind};
             if (ansMax < maxi) {
                 ansMax = maxi;
                 idx = i;
             }
         }
      
      
         while (idx != -1) {
          ans.push_back(w[idx]);
          idx = dp[idx].second;
         }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
