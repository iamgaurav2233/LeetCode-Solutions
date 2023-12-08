class Solution {
public:
    int longestSquareStreak(vector<int>&arr) {
        int dp[100005] = {0};
        sort(arr.begin(),end(nums));
        int mx=0;
        for(auto &n:nums){
            int s = sqrt(n);
            if (s *  s == n) dp[n] = 1 + dp[s];
            else dp[n] = 1;
            mx = max(mx, dp[n]);
        }
        return mx < 2 ? -1 : mx;
    }
};
