class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2)
            return -1;
        sort(nums.begin(), nums.end());
        
        int l=0, r=n-1, ans=-1;
        
        while (l<r) {
            int sum = nums[l] +nums[r];
            if(sum<k) {
                ans = max(ans, sum);
                l++;
            } else
                r--;
        }
        return ans;
    }
};