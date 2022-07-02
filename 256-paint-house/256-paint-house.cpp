class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<3; j++) {
                costs[i][j]+=min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
            }
        }
        
        int ans=INT_MAX;
        for(int i=0; i<3; i++) {
            ans=min(ans, costs[n-1][i]);
        }
        
        return ans;
    }
};