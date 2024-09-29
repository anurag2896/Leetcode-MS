class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int i=0;
        while(i<asteroids.size()) {
            while(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i]) > abs(s.top())) {
                s.pop();
                // i++;
            }

            if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(asteroids[i]) < abs(s.top())) {
                i++;
                continue;
            }

            if(!s.empty() && s.top()>0 && asteroids[i]<0 && abs(s.top())==abs(asteroids[i])) {
                s.pop();
                i++;
                continue;
            }

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