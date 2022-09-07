class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numZeroes=0, global=0, n=nums.size();
        int l=0, r=0;
        while(r<n) {
            if(nums[r]==0) {
                numZeroes++;
            }
            while(numZeroes>1) {
                if(nums[l]==0)
                    numZeroes--;
                l++;
            }
            if(numZeroes<2) {
                global = max(global, r-l+1);
            }
            r++;
        }
        return global;
    }
};