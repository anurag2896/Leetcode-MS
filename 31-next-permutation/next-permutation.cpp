class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int index=-1;
        for(int i=n-1; i>0 ;i--) {
            int curr = nums[i];
            int prev = nums[i-1];
            
            if(curr > prev) {
                index = i-1;
                break;
            } else {
                continue;
            }
        }

        if(index==-1) {
            sort(nums.begin(), nums.end());
            return;
        }


        int nextGreatIndex = -1;
        for(int i=index; i<n; i++) {
            if(nums[i] > nums[index]) {
                if(nextGreatIndex==-1 || nums[i] < nums[nextGreatIndex])
                    nextGreatIndex = i;
            }
        }

        swap(nums[index], nums[nextGreatIndex]);

        
        sort(nums.begin()+index+1, nums.end());
    }
};