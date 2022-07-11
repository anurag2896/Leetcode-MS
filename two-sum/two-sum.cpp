class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //num, index
        int n=nums.size();
        
        for(int i=0; i<n; i++) {
            if(m.find(target-nums[i])!=m.end())
                return vector<int> {i, m[target-nums[i]]};
            m[nums[i]] = i;
        }
        
        return vector<int> {};
    }
};