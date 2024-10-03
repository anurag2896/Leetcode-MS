class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global=INT_MIN, local=0;
        for(auto num:nums) {
            local = max(num, local+num);
            global = max(global, local);
        }
        return global;
    }
};