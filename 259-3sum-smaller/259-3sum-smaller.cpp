class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count=0, n=nums.size();
        if(n<3)
            return count;
        sort(nums.begin(), nums.end());
        int sum=0;
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                sum=nums[i]+nums[l]+nums[r];
                if(sum>=target)
                    r--;
                else {
                    count+=r-l;
                    l++;
                }
            }
        }
        return count;
    }
};