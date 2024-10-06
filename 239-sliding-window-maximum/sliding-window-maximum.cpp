class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  //indexes

        vector<int> ans;
        int n=nums.size();
        
        for(int i=0; i<n; i++) {
            while(!dq.empty() && dq.back() <= i-k)
                dq.pop_back();

            while(!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }

            dq.push_front(i);

            if(i>=k-1)
                ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};