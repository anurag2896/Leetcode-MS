class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX, left=0, n=nums.size(), sum=0;
        for(int i=0; i<n; i++) {
            sum+=nums[i];
            while(left<=i && sum>=target) {
                len = min(len, i-left+1);
                sum-=nums[left++];
            }
        }
        
        if(len==INT_MAX)
            return 0;
        return len;
    }
};