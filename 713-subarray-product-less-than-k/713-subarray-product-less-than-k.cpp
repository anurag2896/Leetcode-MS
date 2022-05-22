class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int prod=1, left=0, n=nums.size(), ans=0;
        for(int i=0; i<n; i++) {
            prod*=nums[i];
            while(prod>=k)
                prod/=nums[left++];
            ans+=i-left+1;
        }
        return ans;
    }
};