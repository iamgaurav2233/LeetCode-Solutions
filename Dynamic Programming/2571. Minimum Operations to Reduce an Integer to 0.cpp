class Solution {
public:
    int minOperations(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        if(n <= 2)
         return 1;
        dp[1] = 1;
        dp[2] = 1;
        int prevPow2 = 2, nextPow2 = 4;
        for(int num=3; num<=n; num++)
         {
             if( (num & (num-1)) == 0 ) 
              {
                  dp[num] = 1;
                  prevPow2 = num;
                  nextPow2 = 2*num;
                  continue;
              } 
             dp[num] = 1 + min(dp[num - prevPow2],dp[nextPow2 - num]);
         }  
        return dp[n];
    }
};
