class Solution {

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, 1e4);

        int step1=0, step2=0;
        for(int i=0; i<n; i++) {
            if(i-1>=0)
                step1 = dp[i-1];

            if(i-2>=0)
                step2 = dp[i-2];
            
            dp[i] = cost[i] + min(step1, step2);
        }
        return min(dp[n-1], dp[n-2]);
    }
};