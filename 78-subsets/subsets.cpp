class Solution {

    void helper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int start) {
        ans.push_back(temp);

        for(int i=start; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums, 0);
        return ans;
    }
};