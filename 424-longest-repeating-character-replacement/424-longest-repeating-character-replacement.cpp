class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxcount=0, n=s.size(), maxlen=0;
        vector<int> m(26, 0);
        int start=0;
        for(int i=0; i<n; i++) {
            m[s[i]-'A']++;
            maxcount = max(maxcount, m[s[i]-'A']);
            
            if(i-start+1-maxcount<=k) {
                maxlen = max(maxlen, i-start+1);
            } else {
                m[s[start]-'A']--;
                start++;
            }
        }
        return maxlen;
    }
};