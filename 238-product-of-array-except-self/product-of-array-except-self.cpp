class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n, 1);

        int l=1, r=1;
        for(int i=0; i<n; i++) {
            temp[i]*=l;
            l*=nums[i];

            temp[n-1-i]*=r;
            r*=nums[n-1-i];
        }
        return temp;
    }
};