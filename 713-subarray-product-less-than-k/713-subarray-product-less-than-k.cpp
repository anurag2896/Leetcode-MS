class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int left=0, n=nums.size(), p=1, count=0;
        for(int i=0; i<n; i++) {
            p*=nums[i];
            while(p>=k) {
                p/=nums[left++];
            }
            count+=i-left+1;
        }
        return count;
    }
};