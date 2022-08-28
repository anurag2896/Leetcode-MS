class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, n=prices.size(), global=0;
        for(int i=1; i<n; i++) {
            profit=max(profit+prices[i]-prices[i-1], 0);
            global = max(global, profit);
        }
        return global;
    }
};