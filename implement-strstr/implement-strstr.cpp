class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size(), h=haystack.size();
        if(n>h)
            return -1;
        int i=0, j=0;
        
        for(int i=0; i<h-n+1; i++) {
            int j, temp=i;
            for(j=0; j<n; j++) {
                if(haystack[temp]==needle[j]) {
                    temp++;
                } else {
                    break;
                }
            }
            if(j==n)
                return i;
        }
        
        return -1;
    }
};