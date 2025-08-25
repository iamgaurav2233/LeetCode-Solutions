public class Solution {
    public int MaxProduct(int n) {
        int firstMax = -1, secondMax = -1;
        while (n != 0) {
            int lastDigit = n % 10;
            n /= 10;
            if (lastDigit >= secondMax) {
                firstMax = secondMax;
                secondMax = lastDigit;
            }
            else if (lastDigit > firstMax) {
                firstMax = lastDigit;
            }
        }
        return firstMax * secondMax;
    }
}