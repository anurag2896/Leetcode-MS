class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> m(128, 0);
        int n=s.size(), left=0, maxlen=0, maxcount=0;   //checks max consectuive char count
        for(int i=0; i<n; i++) {
            m[s[i]]++;
            maxcount = max(maxcount, m[s[i]]);
            while(i+1-left > maxcount + k) {
                m[s[left++]]--;
            }
            maxlen = max(maxlen, i+1-left);
        }
        return maxlen;
    }
};