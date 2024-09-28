class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1, n=nums.size(), count=0, l=0;
        for(int i=0; i<n; i++) {
            product *= nums[i];
            while(l<i && product>=k) {
                product/=nums[l];
                l++;
            }
            if(product<k) {
                count+=i-l+1;
            }
        }
        return count;
    }
};