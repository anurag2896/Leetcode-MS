class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> d;
        vector<int> ans;
        int n=nums.size();
        
        //d:Max F 3, -1, B Min
        //i:1
        
        for(int i=0; i<n; i++) {
            if(!d.empty() && i-k>=0 && d.front()==nums[i-k])
                d.pop_front();
            while(!d.empty() && d.back()<nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            if(i>=k-1)
                ans.push_back(d.front());
        }
        
        return ans;
        
    }
};