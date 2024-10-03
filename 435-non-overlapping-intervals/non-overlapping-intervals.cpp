class compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());

        int min_end = INT_MIN, overlaps=0;
        for(auto i:intervals) {
            if(i[0] >= min_end)
                min_end = i[1];
            else
                overlaps++;
        }
        return overlaps;
    }
};