public class Solution {
    public int MaxFreqSum(string s) {
        Dictionary<char, int> hashMap = new Dictionary<char, int>();
        for (int i = 0;i < s.Length; i++) {
            if (hashMap.ContainsKey(s[i])) {
                hashMap[s[i]]++;
            }
            else {
                hashMap[s[i]] = 1;
            }
        }
        int maximumVowel = 0, maximumConsonant = 0;
        foreach (var kvp in hashMap) {
            if (kvp.Key == 'a' || kvp.Key == 'e' || kvp.Key == 'i' || kvp.Key == 'o' || kvp.Key == 'u') {
                maximumVowel = Math.Max(maximumVowel, kvp.Value);
            }
            else {
                maximumConsonant = Math.Max(maximumConsonant, kvp.Value);
            }
        }
        return maximumConsonant + maximumVowel;
    }
}