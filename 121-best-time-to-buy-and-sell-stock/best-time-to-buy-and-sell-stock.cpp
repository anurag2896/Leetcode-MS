class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int global=0, local=0;
        int n=prices.size();
        for(int i=1; i<n; i++) {
            local = max(0, prices[i]-prices[i-1]+local);
            global = max(global, local);
        }
        return global;
    }
};