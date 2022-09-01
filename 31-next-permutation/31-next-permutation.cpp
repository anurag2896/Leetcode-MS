class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return;
        int index=-1, great_index;
        for(int i=n-2; i>=0; i--) {
            if(nums[i+1]>nums[i]) {
                index=i;
                break;
            }
        }
        
        // cout<<index;
        if(index==-1) {
            sort(nums.begin(), nums.end());
            return;
        } else {
            for(int i=n-1; i>=0; i--) {
                if(nums[i]>nums[index]) {
                    great_index = i;
                    break;
                }
            }
            swap(nums[index], nums[great_index]);
            sort(nums.begin()+index+1, nums.end());
            return;
        }
            
    }
};