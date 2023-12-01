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


class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>> &arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> fi;
        for (int i = 0;i < arr.size(); i++)
            fi.push_back(arr[i][0]);
        vector<int> dp(n + 1, 0);
        for (int i = (int)arr.size() - 1;i >= 0; i--) {
            dp[i] = max(dp[i + 1], arr[i][2]);
            int it = upper_bound(fi.begin(), fi.end(), arr[i][1]) - fi.begin();
            if (it != arr.size())
                dp[i] = max(dp[i], dp[it] + arr[i][2]);
        }      
        return dp[0];
    }
};
