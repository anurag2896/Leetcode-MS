class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), z=0, t=n-1, o=0;
        while(o<=t) {
            if(nums[o]==1)
                o++;
            else if(nums[o]==0) {
                swap(nums[z++], nums[o++]);
            } else if(nums[o]==2) {
                swap(nums[t--], nums[o]);
            }
        }
    }
};