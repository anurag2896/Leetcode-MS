class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), zcount=0, left=0, maxlen=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0)
                zcount++;
            while(zcount>k) {
                if(nums[left++]==0)
                    zcount--;
            }
            maxlen = max(maxlen, i+1-left);
        }
        return maxlen;
    }
};