class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minSoFar = nums[0], maxSoFar = nums[0], tempMax = nums[0], ans=nums[0];

        for(int i=1; i<nums.size(); i++) {
            tempMax = max({nums[i], minSoFar*nums[i], maxSoFar*nums[i]});
            minSoFar = min({nums[i], minSoFar*nums[i], maxSoFar*nums[i]});

            maxSoFar = tempMax;
            ans = max(maxSoFar, ans);
        }
        return ans;
    }
};