class Solution {

    int helper(vector<int>& coins, int amount, vector<vector<int>>& dp, int index) {
        if(index<0 || amount<0)
            return 1e9;
        
        if(amount==0)
            return 0;
        
        if(index==0) {
            if(amount%coins[index]==0)
                return amount / coins[index];
            else
                return 1e9;
        }

        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        int notTake = helper(coins, amount, dp, index-1);
        int take = 1e9;
        if(coins[index] <= amount) {
            take = 1 + helper(coins, amount-coins[index], dp, index);
        }

        return dp[index][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        
        int ans = helper(coins, amount, dp, n-1);
        if(ans==1e9)
            return -1;

        return ans;
    }
};