class Solution {
public:
    int minimizeArrayValue(vector<int>& arr) {
        int n = arr.size();
        auto test = [&](long long mid)->bool{
            long long prev = 0;
            for (int i = n - 1; i >= 1; i--) {
                if (arr[i] + prev > mid) {
                    prev = arr[i] + prev - mid;
                }
                else prev = 0;
            }
            return arr[0] + prev <= mid;
        };
        long long low = 0, high = accumulate(arr.begin(), arr.end(), 0LL);
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (test(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        if (test(low))
            return low;
        else 
            return high;
    }
};
