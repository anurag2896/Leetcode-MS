class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count=0, sum=0, n=nums.size();
        if(n<3)
            return count;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++) {
            int start=i+1, end=n-1;
            while(start<end) {
                sum = nums[i]+nums[start]+nums[end];
                if(sum<target) {
                    count += end-start;
                    start++;
                } else {
                    end--;
                }
            }
        }
        return count;
    }
};