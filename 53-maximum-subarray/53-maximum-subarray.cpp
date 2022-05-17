class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=0, globalMax=INT_MIN;
        for(auto num:nums) {
            currMax = max(num, num+currMax);
            globalMax = max(globalMax, currMax);
        }
        return globalMax;
    }
};