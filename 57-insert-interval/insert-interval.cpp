class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());

        int position = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        if(position==intervals.size())
            intervals.push_back(newInterval);
        else
            intervals.insert(intervals.begin() + position, newInterval);

        vector<vector<int>> ans;
        for(auto i:intervals) {
            if(ans.empty() || ans.back()[1] < i[0])
                ans.push_back(i);
            else {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
        }
        return ans;
    }
};