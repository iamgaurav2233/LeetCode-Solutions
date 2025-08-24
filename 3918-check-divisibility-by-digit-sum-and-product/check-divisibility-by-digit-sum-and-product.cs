public class Solution {
    public bool CheckDivisibility(int number) {
        var copyOfNumber = number;
        var sumOfDigits = 0;
        var productOfDigits = 1;
        while (copyOfNumber != 0) {
            var lastDigit = copyOfNumber % 10;
            sumOfDigits += lastDigit;
            productOfDigits *= lastDigit;
            copyOfNumber /= 10; 
        }
        return number % (sumOfDigits + productOfDigits) == 0;
    }
}