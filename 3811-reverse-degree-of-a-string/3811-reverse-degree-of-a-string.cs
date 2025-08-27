public class Solution {
    public int ReverseDegree(string s) {
        int ans = 0;
        for (int i = 0;i < s.Length; i++) {
            ans += (i + 1) * (123 - (int)s[i]);
        }
        return ans;
    }
}