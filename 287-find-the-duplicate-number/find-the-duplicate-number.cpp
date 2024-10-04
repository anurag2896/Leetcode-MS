class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tort=nums[0], hare=nums[0], n=nums.size();
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while(tort != hare);

        tort = nums[0];
        while(tort != hare) {
            tort = nums[tort];
            hare = nums[hare];
        }
        return tort;
    }
};