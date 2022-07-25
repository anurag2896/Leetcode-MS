class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(), l=1, r=1;
        vector<int> ans(n, 1);
        
        for(int i=0; i<n; i++) {
            ans[i]*=l;
            l*=nums[i];
            ans[n-1-i]*=r;
            r*=nums[n-1-i];
        }
        
        return ans;
    }
};