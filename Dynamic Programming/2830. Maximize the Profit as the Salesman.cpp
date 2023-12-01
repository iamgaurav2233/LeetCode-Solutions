class Solution {
public:
    int dp[100001];
    int recur(int i, vector<vector<int>> &arr) {
        if (i == arr.size())
            return 0;
          if (dp[i] != -1)
            return dp[i];
        vector<int> temp{arr[i][1] + 1, 0, 0};
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        int ans = recur((it - arr.begin()), arr) + arr[i][2];
        return dp[i] = max(recur(i + 1, arr), ans);
    }
    int maximizeTheProfit(int n, vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        memset(dp, -1, sizeof(dp));
        int ans = recur(0, arr);
        return ans;
    }
};
