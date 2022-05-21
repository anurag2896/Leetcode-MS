class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=0, diff=INT_MAX, global_sum;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                    return sum;
                if(abs(sum-target)<diff) {
                    global_sum=sum;
                    diff = abs(sum-target);
                }
                if(sum>target)
                    r--;
                else
                    l++;
            }
        }
        return global_sum;
    }
};