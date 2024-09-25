class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for(int i=1; i<intervals.size(); i++) {
            int start = max(intervals[i][0], intervals[i-1][0]);
            int end = min(intervals[i][1], intervals[i-1][1]);

            if(start < end)
                return false;
        }
        return true;
    }
};