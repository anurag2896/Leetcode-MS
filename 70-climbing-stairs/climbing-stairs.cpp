class Solution {

    vector<int> dp;

    int helper(int n, vector<int>& dp) {
        if(n<=0)
            return dp[n] = 0;
        
        if(n==1 || n==2)
            return dp[n] = n;

        if(dp[n]!=-1)
            return dp[n];
        
        int takePrev = helper(n-1, dp);
        int takePrevPrev = helper(n-2, dp);
        return dp[n] = takePrev + takePrevPrev;
    }

public:
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        helper(n, dp);
        return dp[n];
    }
};