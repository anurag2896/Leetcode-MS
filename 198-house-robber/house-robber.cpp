class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);

        for(int i=0; i<n; i++) {
            // take current & prev of previous and skip previous
            // or take previious

            if(i==0)
                dp[i] = nums[i];
            else if(i==1) 
                dp[i] = max(nums[i], dp[i-1]);
            else
                dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};