class Solution {
public:
    bool helper(vector<int> ref, vector<int> m) {
        for(int i=0; i<128; i++) {
            if(ref[i]!=m[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> ref(128, 0), m(128, 0);
        int n1=s1.size(), n2=s2.size();
        
        if(n1>n2)
            return false;
        
        for(int i=0; i<n1; i++) {
            ref[s1[i]]++;
            m[s2[i]]++;
        }
        
        int left=0;
        for(int i=n1; i<n2; i++) {
            if(m[s2[left]]==ref[s2[left]] && helper(ref, m)) {
                return true;
            } else {
                m[s2[left++]]--;
            }
            m[s2[i]]++;
        }
        if(helper(ref, m))
            return true;
        return false;
    }
};