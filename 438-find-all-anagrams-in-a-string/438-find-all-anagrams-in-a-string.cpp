class Solution {
public:
    bool helper(vector<int> mp, vector<int> ms) {
        for(int i=0; i<128; i++) {
            if(mp[i]!=ms[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int np=p.size(), ns=s.size();
        vector<int> mp(128, 0), ms(128, 0);
        int left=0;
        vector<int> ans;
        if(np>ns)
            return ans;
        
        for(int i=0; i<np; i++) {
            mp[p[i]]++;
            // ms[s[i]]++;
        }
        
        for(int i=0; i<ns; i++) {
            ms[s[i]]++;
            if(i>=np)
                ms[s[left++]]--;
            
            if(mp[s[left]]==ms[s[left]] && helper(mp, ms)) {
                ans.push_back(left);
            }
            
            
        }
        
        // if(helper(mp, ms))
        //     ans.push_back(left);
        
        return ans;
    }
};