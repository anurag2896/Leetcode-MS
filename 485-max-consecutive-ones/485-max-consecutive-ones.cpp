class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, n=nums.size(), global=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==1)
                count++;
            else {
                global=max(global, count);
                count=0;
            }
        }
        global=max(global, count);
        return global;
    }
};