class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int count=0, avg_val=0, n=nums.size();
        // for(auto num:nums) {
        //     avg_val+=num;
        // }
        // avg_val/=n;
        sort(nums.begin(), nums.end());
        avg_val = nums[n/2];
        
        for(int num:nums) {
            count+=abs(avg_val-num);
        }
        
        return count;
    }
};