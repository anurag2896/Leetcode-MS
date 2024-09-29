class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int global=0, local=0, maxPrice = 0, n=prices.size();
        for(int i=n-1; i>=0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            if(maxPrice > prices[i]) {
                global = max(global, maxPrice - prices[i]);
            }
        }

        return global;
    }
};