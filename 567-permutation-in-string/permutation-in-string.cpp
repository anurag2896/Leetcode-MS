class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1m(256, 0), s2m(256, 0);
        if(s1.size() > s2.size())
            return false;
        
        for(int i=0; i<s1.size(); i++) {
            s1m[s1[i]]++;
            s2m[s2[i]]++;
        }

        if(s1m==s2m) {
            return true;
        }

        int n=s2.size(), l=0;
        for(int i=s1.size(); i<s2.size(); i++) {
            s2m[s2[i]]++;
            s2m[s2[l]]--;
            l++;
            if(s1m==s2m) {
                return true;
            }
        }
        return false;
    }
};