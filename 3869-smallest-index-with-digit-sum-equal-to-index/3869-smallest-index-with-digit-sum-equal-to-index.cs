public class Solution {
    public int SmallestIndex(int[] nums) {
        for (int i = 0;i < nums.Length; i++) {
            int sum = 0;
            while (nums[i] != 0) {
                sum += nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
            if (sum == i)
              return i;
        }
        return -1;
    }
}