public class Solution {
    public string GenerateTag(string caption) {
        caption = caption.Trim();
        caption = caption.ToLower();
        List<string> list = caption.Split(' ', StringSplitOptions.RemoveEmptyEntries).ToList();
        for (int i = 1;i < list.Count; i++) {
            char[] tempArray = list[i].ToCharArray();
            tempArray[0] = char.ToUpper(tempArray[0]);
            list[i] = new String(tempArray);
        }
        string ansString = "#" + string.Join("", list);
        if (ansString.Length >= 100) {
            return ansString.Substring(0, 100);
        }
        return ansString;
    }
}