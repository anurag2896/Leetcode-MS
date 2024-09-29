class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int i=0;
        while(i<asteroids.size()) {
            // if incoming is greater and clashing then keep popping from existing
            while(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i]) > abs(s.top())) {
                s.pop();
                // i++;
            }

            // if incoming is smaller and clashing then dont consider it
            if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i]) < abs(s.top())) {
                i++;
                continue;
            }

            // if incoming is same and clashing then remove both
            if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(s.top())==abs(asteroids[i])) {
                s.pop();
                i++;
                continue;
            }

            // if incoming is is same size and and same direcrtino or opposite direction but not clashing then consider it
            if(s.empty() || (s.top()>0 && asteroids[i]>0) || (s.top()<0 && asteroids[i]<0) || (s.top()<0 && asteroids[i]>0 )) {
                s.push(asteroids[i]);
            }
            i++;
        }

        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};