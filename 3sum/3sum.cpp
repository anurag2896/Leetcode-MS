class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int sum, target=0;
        
        for(int i=0; i<n-2; i++) {
            int start=i+1, end=n-1;
            while(start<end) {
                sum = nums[i]+nums[start]+nums[end];
                if(sum==target) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start<end && nums[start]==nums[start+1])
                        start++;
                    while(start<end && nums[end]==nums[end-1])
                        end--;
                    start++; end--;
                } else if(sum>target) {
                    end--;
                } else
                    start++;
            }
            while(i<n-2 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};