class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum = n*(n+1)/2, calc_sum = 0;
        
        for(auto num:nums) {
            calc_sum+=num;
        }
        
        return sum-calc_sum;
    }
};