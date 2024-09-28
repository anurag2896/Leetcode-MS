class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;      //num, {freq, l, r}
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i])==m.end()) {
                m[nums[i]] = {1, i, i};
            } else {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;;
            }
        }

        int max_count=0, min_range=1e9;
        for(auto ele:m) {
            if(ele.second[0] >= max_count) {
                if(max_count == ele.second[0]) {
                    min_range = min(min_range, ele.second[2] - ele.second[1] + 1);
                } else {
                    max_count = ele.second[0];
                    min_range = ele.second[2] - ele.second[1] + 1;
                }
            }
        }

        return min_range;
    }
};