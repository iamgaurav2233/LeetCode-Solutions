public class Solution {
    public long MinCuttingCost(int firstLog, int secondLog, int maximumLoad) {
        if (firstLog > maximumLoad && secondLog > maximumLoad) {
            throw new ArgumentException("Arguments are invalid");
        }

        long longestLog = Math.Max(firstLog, secondLog);

        if (longestLog - maximumLoad > maximumLoad) {
            throw new ArgumentException("Arguments are invalid");
        } 
    
        if (firstLog <= maximumLoad && secondLog <= maximumLoad) {
            return 0;
        }

        return (long)maximumLoad * (longestLog - maximumLoad);
    }
}