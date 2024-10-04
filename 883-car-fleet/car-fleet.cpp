class comparator {
public:
    bool operator()(const vector<float>&a, const vector<float>&b) {
        if(a[0]==b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<vector<float>> agg;
        for(int i=0; i<n; i++) {
            float dist = target-position[i];
            float time = dist/speed[i];
            agg.push_back({(float)position[i], time});
        }

        sort(agg.begin(), agg.end(), comparator());

        int fleet=0;
        float max_time=0;
        for(int i=n-1; i>=0; i--) {
            if(agg[i][1] > max_time) {
                fleet++;
                max_time = agg[i][1];
            }
        }
        return fleet;
    }
};