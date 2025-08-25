public class Solution {
    public bool isSorted(List<int> nums) {
        for (int i = 1; i < nums.Count; i++) {
            if (nums[i] < nums[i - 1])
            return false;
        }
        return true;
    }
    public int MinimumPairRemoval(int[] arr) {
        int ans = 0;
         List<int> nums = arr.ToList();
        while (nums.Count != 1 && !isSorted(nums)) {
            ans++;
            int maximumSum = 200000, index = -1;
            for (int i = 1;i < nums.Count; i++) {
                if (maximumSum > nums[i] + nums[i - 1]) {
                    maximumSum = nums[i] + nums[i - 1];
                    index = i;
                }
            }
            nums.RemoveAt(index);
            nums.RemoveAt(index - 1);
            nums.Insert(index - 1, maximumSum);
        }
        return ans;
    }
}