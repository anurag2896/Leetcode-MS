class Solution {

    int helper(int index, vector<int>& nums, vector<int>& dp) {
        if(index<0)
            return INT_MIN;
        
        if(index==0)
            return nums[0];

        if(dp[index]!=-1)
            return dp[index];
        
        int notTake = helper(index-1, nums, dp);
        int take = nums[index];
        if(index-2>=0)
            take += helper(index-2, nums, dp);

        return dp[index] = max(take, notTake);


    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);

        return helper(n-1, nums, dp);
    }
};