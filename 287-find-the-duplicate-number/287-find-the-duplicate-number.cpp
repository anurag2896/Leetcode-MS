class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare=nums[0], tortoise=nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[hare];
            hare = nums[hare];
        } while(hare!=tortoise);
        tortoise = nums[0];
        while(tortoise!=hare) {
            tortoise = nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};