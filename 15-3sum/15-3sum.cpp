class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                int sum = -(nums[l] + nums[r]);
                if(sum==nums[i]) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1])
                        l++;
                    while(l<r && nums[r]==nums[r-1])
                        r--;
                    l++;
                    r--;
                } else if(sum>nums[i])
                    l++;
                else
                    r--;
            }
            while(i<n-2 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};