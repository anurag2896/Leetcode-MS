class Solution {
public:
    int checkPalindrome(string s, int i, int n, bool mode=false) {   //returns start, maxlen
        int l=i, r=i;
        if(mode){
            l=i;
            r=i+1;
        }
        while(l>=0 && r<n && s[l]==s[r]) {
            // start=l;
            // maxlen = r-l+1;
            l--;
            r++;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0, start=0;
        for(int i=0; i<n; i++) {
            int ans = checkPalindrome(s, i, n);
            if(ans>maxlen) {
                start = i-ans/2;
                maxlen = ans;
            }
        }
        
        for(int i=0; i<n-1; i++) {
            int ans = checkPalindrome(s, i, n, true);
            if(ans>maxlen) {
                start = i-ans/2+1;
                maxlen = ans;
            }
        }
        // cout<<maxlen<<" "<<start<<endl;
        return s.substr(start, maxlen);
    }
};