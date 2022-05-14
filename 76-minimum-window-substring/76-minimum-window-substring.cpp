class Solution {
public:
    bool check(vector<int> ref, vector<int> m) {
        for(int i=0; i<128; i++) {
            if(m[i]<ref[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> ref(128, 0), m(128, 0);
        int n=s.size(), ts=t.size();
        if(ts>n)
            return "";
        
        for(auto c:t)
            ref[c]++;
        
        int start=0, end=0;
        string ans="";
        int minLen = n;
        for(end=0; end<n; end++) {
            m[s[end]]++;
            while(check(ref, m)) {
                int range = end-start+1;
                if(minLen >= range) {
                    minLen = min(minLen, range);
                    ans = s.substr(start, range);
                }
                m[s[start]]--;
                start++;
            }
        }
        
        return ans;
    }
};