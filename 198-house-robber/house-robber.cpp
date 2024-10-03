class Solution {

    int helper(vector<int>& nums, vector<int>& dp, int n) {
        if(n<0)
            return 0;
        
        if(n==0)
            return dp[n] = nums[0];

        if(dp[n]!=-1)
            return dp[n];

        int take = nums[n] + helper(nums, dp, n-2);
        int nottake = helper(nums, dp, n-1);

        return dp[n] = max(take, nottake);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        helper(nums, dp, n-1);
        return dp[n-1];
    }
};