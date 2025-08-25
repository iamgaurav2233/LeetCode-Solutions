public class Solution {
    public int FindClosest(int x, int y, int z) {
        if (Math.Abs(x - z) == Math.Abs(y - z)) {
            return 0;
        }
        else if (Math.Abs(x - z) > Math.Abs(y - z)) {
            return 2;
        }
        else return 1;
    }
}