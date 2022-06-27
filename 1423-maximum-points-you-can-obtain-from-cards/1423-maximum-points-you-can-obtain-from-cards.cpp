class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // int dp[k+1][k+1]={0};
        int ans = 0, n=cardPoints.size(), sum=0, totSum=0;
        for(int i=0; i<n-k; i++) {
            sum+=cardPoints[i];
        }
        
        for(auto points:cardPoints)
            totSum+=points;
        
        // cout<<totSum<<" "<<sum<<endl;
        
        int left=0;
        ans=totSum-sum;
        for(int i=n-k; i<n; i++) {
            sum+=cardPoints[i%n]-cardPoints[left++];
            ans = max(ans, totSum-sum);
            
        }
        
        return ans;
    }
};