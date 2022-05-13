class Solution {
public:
    bool check(vector<int> ref, vector<int> m) {
        for(int i=0; i<26; i++) {
            if(ref[i]!=m[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> ref(26, 0), m(26, 0);
        int n=s1.size(), n2=s2.size();
        
        if(n>n2)
            return false;

        int start=0, end=0;
        for(end=0; end<n; end++) {
            ref[s1[end]-'a']++;
            m[s2[end]-'a']++;
        }
        
        while(end<n2) {
            if(ref[s2[start]-'a']==m[s2[start]-'a'] && check(ref, m)) {
                return true;
            } else {
                m[s2[start]-'a']--;
                start++;
                m[s2[end]-'a']++;
                end++;
            }
        }
        
        if(check(ref, m))
            return true;
        return false;
        
    }
};