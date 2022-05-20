class Solution {
public:
    bool helper(vector<int> smap, vector<int> tmap) {
        for(int i=0; i<128; i++) {
            if(smap[i]<tmap[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> tmap(128, 0), smap(128, 0);
        int left=0, slen=s.size(), tlen=t.size();
        int minlen = slen;
        string ans="";
        
        if(tlen>slen)
            return ans;
        
        for(int i=0; i<tlen; i++) {
            // smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        
        for(int i=0; i<slen; i++) {
            smap[s[i]]++;
            while(helper(smap, tmap)) {
                if(minlen>=i-left+1) {
                    minlen = i-left+1;
                    ans=s.substr(left, i-left+1);
                }
                smap[s[left++]]--;
            }
        }
        
        return ans;
    }
};