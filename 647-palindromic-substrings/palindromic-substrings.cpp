class Solution {

    int helper(string s, int l, int r){
        int n=s.size(), count=0;
        while(l>=0 && r<n && s[l]==s[r]) {
            l--;
            r++;
            count++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.size();
        for(int i=0; i<n; i++) {
            count+=helper(s, i, i);
            count+=helper(s, i, i+1);
        }
        return count;
    }
};