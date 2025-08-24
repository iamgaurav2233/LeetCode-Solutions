public class Solution {
    public bool IsTrionic(int[] nums) {
        if (nums[1] <= nums[0])
           return false;
        int change = 0;
        bool isIncreasingSequence = true;
        for (int i = 2;i < nums.Length; i++) {
            if (isIncreasingSequence) {
                if (nums[i] < nums[i - 1]) {
                    change++;
                    isIncreasingSequence = false;
                }
                else if (nums[i] == nums[i - 1])
                     return false;
            }
            else {
                if (nums[i] > nums[i - 1]) {
                    change++;
                    isIncreasingSequence = true;
                }
                else if (nums[i] == nums[i - 1])
                     return false;
            }
            if (change >= 4)
               return false;
        }
        return (change == 2);
    }
}