class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int rooms=0;
        map<int, int> m;
        for(auto i:intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }

        int count=0;
        for(auto ele:m) {
            count+=ele.second;
            rooms = max(rooms, count);
        }
        return rooms;
    }
};