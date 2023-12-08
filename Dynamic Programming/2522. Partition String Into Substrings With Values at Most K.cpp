class Solution {
public:
    int minimumPartition(string s, int K) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int i = n - 1;i >= 0; i--) {
            if ((s[i] - '0') > K)
                return -1;
            long long sum = 0;
            for (int j = i;j < n; j++) {
                sum = (sum * 10) + (s[j] - '0'); 
                if (sum > K) 
                    break;
                dp[i] = min(dp[i], dp[j + 1] + 1);
            }
        }
        return dp[0];
    }
};
