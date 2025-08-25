public class Solution {
    public int MostFrequentEven(int[] nums) {
        Dictionary<int, int> frequencyMap = new Dictionary<int, int> ();
        int lengthOfArray = nums.Length;
        for (int i = 0;i < lengthOfArray; i++) {
            if (frequencyMap.ContainsKey(nums[i])) {
                frequencyMap[nums[i]]++;
            }
            else {
                frequencyMap[nums[i]] = 1;
            }
        }
        int maximumFrequency = 0, answerElement = -1;
        foreach (var kvp in frequencyMap) {
            if (kvp.Key % 2 == 0 && maximumFrequency <= kvp.Value) {                
                if (maximumFrequency == kvp.Value && answerElement != -1) {
                    answerElement = Math.Min(answerElement, kvp.Key);
                }
                else {
                    answerElement = kvp.Key;
                }
                maximumFrequency = kvp.Value;
            }
        }
        return answerElement;
    }
}