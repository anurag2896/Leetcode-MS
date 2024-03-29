class Solution {
public:
    bool check(vector<int> ref, vector<int> test) {
        for(int i=0; i<128; i++) {
            if(test[i]<ref[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int slen=s.size(), tlen=t.size();
        string ans="";
        if(tlen>slen)
            return ans;
        
        vector<int> ref(128, 0), test(128, 0);
        
        for(int i=0; i<tlen; i++) {
            ref[t[i]]++;
            // test[s[i]]++;
        }
        
        if(check(ref, test))
            return s.substr(0, tlen);
        
        int left=0, len=slen, start=0;
        
        for(int i=0; i<slen; i++) {
            test[s[i]]++;
            
            //if we do test
            
            while(check(ref, test)) {
                // test[s[left]]--;
                if(i-left+1<=len) {
                    start=left;
                    len=i-left+1;
                    ans = s.substr(start, len);
                }
                // left++;
                test[s[left++]]--;
            }
        }
        
        
        return ans;
    }
};