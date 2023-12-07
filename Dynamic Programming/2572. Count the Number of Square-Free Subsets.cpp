const int mod = 1e9 + 7;
class Solution {
public:
    long long powmod(long long a, long long b, long long mod) {long long res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

    int dp[1001][(1 << 11)];
    int recur(int i, int j, vector<int> &arr, vector<int> &p) {
        if (i == arr.size()) {
            if (j == 0)
                return 0;
            else 
                return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
       int ans = 0;
       int temp = arr[i];
        int mask = j;
        int k = (int)p.size() - 1;
        int flag = 1;
       while (temp != 1) {
           if (temp % p[k] == 0) {
               temp = temp / p[k];
               if (((1 << k) & mask)) {
                   flag = 0;
                   break;
               }
               mask = (mask | (1 << k));
           }
           else k--;
       }
        if (flag) {
            ans = (ans + recur(i + 1, mask, arr, p)) % mod;
        }
        ans = (ans + recur(i + 1, j, arr, p)) % mod;
        return dp[i][j] = ans;
    }
    int squareFreeSubsets(vector<int> &arr) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        int ans = recur(0, 0, arr, p);
        int cnt = 0;
        for (int i = 0;i < n; i++) {
            if (arr[i] == 1) {
                cnt++;
            }
        }
        if (cnt == arr.size())
            return (powmod(2, cnt, mod) - 1 + mod) % mod;
        ans = (ans + powmod(2, cnt, mod) - 1 + mod) % mod;
        return ans;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------

const int mod = 1e9 + 7;

class Solution {
public:
    long long powmod(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }

    int squareFreeSubsets(vector<int>& arr) {
        vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int n = arr.size();
        int maxMask = (1 << p.size()) - 1;

        vector<vector <int>> dp(n + 1, vector<int>(maxMask + 1, 0));

        for (int mask = 0; mask <= maxMask; ++mask) {
            dp[n][mask] = (mask == 0) ? 0 : 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= maxMask; ++j) {
                int ans = 0;
                int temp = arr[i];
                int mask = j;
                int k = p.size() - 1;
                int flag = 1;

                while (temp != 1) {
                    if (temp % p[k] == 0) {
                        temp = temp / p[k];
                        if (((1 << k) & mask)) {
                            flag = 0;
                            break;
                        }
                        mask = (mask | (1 << k));
                    } else {
                        k--;
                    }
                }

                if (flag) {
                    ans = (ans + dp[i + 1][mask]) % mod;
                }
                ans = (ans + dp[i + 1][j]) % mod;

                dp[i][j] = ans;
            }
        }

        int ans = dp[0][0];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                cnt++;
            }
        }

      
        ans = (ans + powmod(2, cnt, mod) - 1 + mod) % mod;
        return ans;
    }
};
