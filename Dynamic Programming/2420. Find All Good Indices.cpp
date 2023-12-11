class Solution {
public:
    vector<int> goodIndices(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp1(n + 2, 0);
        vector<int> dp2(n + 2, 0);
        dp1[0] = -1e9;
        dp1[n + 1] = -1e9;
        dp2[0] = -1e9;
        dp2[n + 1] = -1e9;
        
        for (int i = 2;i <= n; i++) {
            if (arr[i - 1] <= arr[i - 2]) {
                dp1[i] = dp1[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (arr[i - 1] <= arr[i]) {
                dp2[i] = dp2[i + 1] + 1;
            }
        }
        vector<int> ans;
        for (int i = 1;i <= n; i++) {
            if (dp1[i - 1] + 1 >= k and dp2[i + 1] + 1 >= k) {
                ans.push_back(i - 1);
            }
        }
        return ans;
    }
};
