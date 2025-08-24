using System.Text.RegularExpressions;

public class Solution
{
    private static readonly Regex CouponRegex =
        new Regex(@"^[A-Za-z0-9_]+$", RegexOptions.Compiled);

    public enum BusinessLine
    {
        Electronics = 1,
        Grocery     = 2,
        Pharmacy    = 3,
        Restaurant  = 4
    }

    private class Coupon
    {
        public string Code { get; set; }
        public BusinessLine BusinessLine { get; set; }
    }

    public IList<string> ValidateCoupons(
        string[] code, string[] businessLine, bool[] isActive)
    {
        if (code.Length != businessLine.Length || code.Length != isActive.Length)
            throw new ArgumentException("Input arrays must have the same length.");

        var validCoupons = new List<Coupon>();

        for (int i = 0; i < code.Length; i++)
        {
            if (isActive[i]
                && CouponRegex.IsMatch(code[i])
                && Enum.TryParse(businessLine[i], true, out BusinessLine line))
            {
                validCoupons.Add(new Coupon
                {
                    Code = code[i],
                    BusinessLine = line
                });
            }
        }

        validCoupons.Sort((a, b) =>
            a.BusinessLine != b.BusinessLine
                ? a.BusinessLine.CompareTo(b.BusinessLine)
                : StringComparer.Ordinal.Compare(a.Code, b.Code));

        return validCoupons.Select(c => c.Code).ToList();
    }
}
