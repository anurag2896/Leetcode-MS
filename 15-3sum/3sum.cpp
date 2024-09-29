class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++) {
            int l=i+1, r=n-1;
            while(l<r) {
                int sum = nums[l] + nums[r] + nums[i];
                if(sum==0) {
                    while(l<r && nums[l]==nums[l+1]) {
                        l++;
                    }

                    while(l<r && nums[r]==nums[r-1]) {
                        r--;
                    }

                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if(sum<0) {
                    l++;
                } else {
                    r--;
                }
            }

            while(i<n-2 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};