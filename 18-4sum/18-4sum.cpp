class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<4)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                int l=j+1, r=n-1;
                while(l<r) {
                    int temp=target-(nums[i] + nums[j]);
                    int sum = nums[l] + nums[r];
                    if(sum==temp) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1])
                            l++;
                        while(l<r && nums[r]==nums[r-1])
                            r--;
                        l++;
                        r--;
                    } else if(sum<temp)
                        l++;
                    else
                        r--;
                }
                while(j<n-3 && nums[j]==nums[j+1])
                    j++;
            }
            while(i<n-4 && nums[i]==nums[i+1])
                    i++;
        }
        return ans;
    }
};