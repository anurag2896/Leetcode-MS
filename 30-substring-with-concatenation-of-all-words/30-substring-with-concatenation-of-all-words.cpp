class Solution {
public:
    bool helper(vector<int> ref, vector<int> m, string s, unordered_map<string, int> sref, int len, int start, int totlen) {
        // for(int i=0; i<128; i++) {
        //     if(ref[i]!=m[i])
        //         return false;
        // }
        for(int i=start; i<start+totlen; i=i+len) {
            string t = s.substr(i, len);
            if(sref.find(t)==sref.end())
                return false;
            sref[t]--;
        }
        for(auto el:sref) {
            if(el.second!=0)
                return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> sref;
        vector<int> ref(128, 0), m(128, 0);
        int left=0, totwords = words.size(), wlen = words[0].size(), n=s.size();
        
        vector<int> ans;
        
        for(auto w:words) {
            sref[w]++;
            for(auto c:w) {
                ref[c]++;
            }
        }
        
        int totlen = wlen*totwords;
        for(int i=0; i<n; i++) {
            m[s[i]]++;
            if(i>=totlen) {
                m[s[left++]]--;
            }
            
            if(i>=totlen-1 && helper(ref, m, s, sref, wlen, left, totlen))
                ans.push_back(left);
        }
        
        return ans;
    }
};