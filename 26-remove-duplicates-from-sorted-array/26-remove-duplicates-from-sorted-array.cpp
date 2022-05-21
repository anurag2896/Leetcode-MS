class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=1, count=1;
        if(n<2)
            return n;
        
        while(r<n) {
            if(nums[l]==nums[r]) {
                r++;
            } else {
                count++;
                l++;
                swap(nums[l], nums[r++]);
            }
        }
        return count;
    }
};