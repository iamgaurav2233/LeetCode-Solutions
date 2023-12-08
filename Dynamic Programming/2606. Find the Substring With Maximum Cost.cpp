class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
       int n = chars.size();
        map<char,int> mp1,mp2;
        for (int i = 0;i < n; i++) {
            mp1[chars[i]] = 1;
            mp2[chars[i]] = vals[i];
       }
       int sum = -2e9;
       int maxi = 0;
       for (int i = 0;i < s.size(); i++) {
           int temp;
           if (mp1[s[i]])
               temp = mp2[s[i]];
           else 
               temp = (s[i] - 'a') + 1;
           if (temp + sum > temp) {
               sum = sum + temp;
           }
           else sum = temp;
           maxi = max(maxi, sum);
       }
       return maxi;
    }
};
