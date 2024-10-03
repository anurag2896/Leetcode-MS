class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end());

        int start=INT_MIN, end=INT_MAX;
        for(int i=0; i<intervals.size()-1; i++) {
            auto curr = intervals[i];
            auto next = intervals[i+1];

            int maxStart = max(curr[0], next[0]);
            int minEnd = min(curr[1], next[1]);

            if(minEnd > maxStart)
                return false;
        }
        return true;
    }
};