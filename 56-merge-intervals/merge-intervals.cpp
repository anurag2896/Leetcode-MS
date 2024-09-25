class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++) {
            if(ans.empty())
                ans.push_back(intervals[i]);
            else {
                int back_ele = ans.back()[1];
                if(intervals[i][0] > back_ele) {
                    ans.push_back(intervals[i]);
                } else {
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
            }
        }
        return ans;
    }
};