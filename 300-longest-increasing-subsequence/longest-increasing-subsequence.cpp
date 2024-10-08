class Solution {

    int helper(vector<int>& nums, int index, vector<vector<int>>& dp, int prevIndex) {
        int n = nums.size();
        if(index==n)
            return 0;
        
        if(dp[index][prevIndex+1]!=-1)
            return dp[index][prevIndex+1];
        
        int notTake = helper(nums, index+1, dp, prevIndex);
        int take = 0;
        if(prevIndex==-1 || nums[index] > nums[prevIndex])
            take = 1 + helper(nums, index+1, dp, index);

        return dp[index][prevIndex+1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // dp[0] = 1;

        return helper(nums, 0, dp, -1);
    }
};