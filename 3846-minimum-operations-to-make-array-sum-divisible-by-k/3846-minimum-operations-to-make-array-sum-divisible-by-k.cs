public class Solution {
    public int MinOperations(int[] nums, int k) {
        var ans = 0;
        foreach (var num in nums) {
            ans += num;
        }
        return ans % k;
    }
}