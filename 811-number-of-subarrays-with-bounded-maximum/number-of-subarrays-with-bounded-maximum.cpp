class Solution {

    int helper(vector<int>& nums, int bound) {
        int ans=0, count=0, n=nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] > bound)
                count=0;
            else
                count+=1;
            
            ans+=count;
        }
        return ans;
    }

public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return helper(nums, right) - helper(nums, left-1);
    }
};