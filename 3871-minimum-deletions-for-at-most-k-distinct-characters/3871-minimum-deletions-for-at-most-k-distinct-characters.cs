public class Solution {
    public int MinDeletion(string s, int k) {
        Dictionary<char, int> frequencyMap = new Dictionary<char, int> ();
        for (int i = 0;i < s.Length; i++) {
            if (frequencyMap.ContainsKey(s[i]))
            frequencyMap[s[i]]++;
            else
            frequencyMap[s[i]] = 1;
        }
        PriorityQueue<char, int> pq = new PriorityQueue<char, int> ();
        foreach (var kvp in frequencyMap) {
            pq.Enqueue(kvp.Key, kvp.Value);
        }
        int ans = 0;
        while (pq.Count > k) {
            pq.TryDequeue(out char element, out int priority);
            ans += priority;
        }
        return ans;
    }
}