public class Solution {
    public int SmallestNumber(int n) {
        for (int i = 0;i <= 30; i++) {
            if ((int)Math.Pow(2, i) - 1 >= n) {
                return (int)Math.Pow(2, i) - 1;
            }
        }
        return 0;
    }
}